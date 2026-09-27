#include "QuestSubsystem.h"
#include "QuestStep_Base.h"

void UQuestSubsystem::InitializeQuestSystem(UDataTable* InDataTable)
{
	if (InDataTable != nullptr)
	{
		QuestDataTableAsset = InDataTable;
		UE_LOG(LogTemp, Warning, TEXT("Quest System Initialised!"));
	}
}

void UQuestSubsystem::StartQuestStep(FGameplayTag StartingTag)
{
	if (QuestDataTableAsset == nullptr) return;
	if (ActiveQuestInstances.Contains(StartingTag) || CompletedQuests.HasTagExact(StartingTag)) return;

	FQuestDatabase* QuestRow = QuestDataTableAsset->FindRow<FQuestDatabase>(StartingTag.GetTagName(), TEXT("StartQuest Lookup"));

	if (QuestRow != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("ATTEMPTING TO START NEXT QUEST STEP: %s "), *StartingTag.ToString());

		// Determine Class to Spawn
		TSubclassOf<UQuestStep_Base> ClassToSpawn = QuestRow->CustomStepLogic;
		if (!ClassToSpawn)
		{
			// Automatically fall back to the default Blueprint class. not the C++ class!!!
			ClassToSpawn = StaticLoadClass(UQuestStep_Base::StaticClass(), nullptr, TEXT("/Game/Quests/BP_QuestStep_Default.BP_QuestStep_Default_C"));
			if (!ClassToSpawn)
			{
				UE_LOG(LogTemp, Error, TEXT("Failed to load default quest step BP. Was it moved or renamed?"));
				return;
			}
		}
		// Construct the Object
		UQuestStep_Base* NewStep = NewObject<UQuestStep_Base>(this, ClassToSpawn);
		// Add to Map & Initialize (which binds it to dispatchers)
		ActiveQuestInstances.Add(StartingTag, NewStep);
		NewStep->InitializeStep(*QuestRow, this);

		OnQuestStepStarted.Broadcast(StartingTag);
	}
}

void UQuestSubsystem::FinishQuestStep(FGameplayTag StepTag)
{
	UE_LOG(LogTemp, Warning, TEXT("FINISHING QUEST STEP: %s "), *StepTag.ToString());

	if (UQuestStep_Base** FoundStep = ActiveQuestInstances.Find(StepTag))
	{
		// find the row to check for NextStep
		FQuestDatabase* QuestRow = QuestDataTableAsset->FindRow<FQuestDatabase>(StepTag.GetTagName(), TEXT("FinishQuest Lookup"));

		if (QuestRow != nullptr)
		{
			// Grant Rewards Logic Here. NOT USED. Only if we plan on giving rewards in game sessions. Rewards are currently handled by the NPC's
			if (QuestRow->Rewards.Num() > 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("GRANT REWARDS (Logic TBD)"));
			}

			// Add to Completed Quests
			CompletedQuests.AddTag(StepTag);
			if (QuestRow->QuestLineTag.IsValid())
			{
				CompletedQuests.AddTag(QuestRow->QuestLineTag); // Add parent line to completed
			}

			// Clean up
			ActiveQuestInstances.Remove(StepTag);
			OnQuestStepCompleted.Broadcast(StepTag);

			// Start next step if one exists
			if (QuestRow->NextStepTag.IsValid())
			{
				StartQuestStep(QuestRow->NextStepTag);
			}
		}
	}
}

// NOT USED YET. Some Temporary jargon for my own satisfaction (josh)
TArray<FActiveQuestSaveData> UQuestSubsystem::ExtractSaveData() const
{
	TArray<FActiveQuestSaveData> SavedArray;
	for (auto& Pair : ActiveQuestInstances)
	{
		if (Pair.Value)
		{
			SavedArray.Add(Pair.Value->GetSaveData());
		}
	}
	return SavedArray;
}
// More temp placements
void UQuestSubsystem::RestoreSaveData(const TArray<FActiveQuestSaveData>& SavedData)
{
	ActiveQuestInstances.Empty();
	for (const FActiveQuestSaveData& Data : SavedData)
	{
		StartQuestStep(Data.QuestStepTag);
		if (UQuestStep_Base** RestoredStep = ActiveQuestInstances.Find(Data.QuestStepTag))
		{
			(*RestoredStep)->RestoreFromSave(Data);
		}
	}
}

// BROADCASTS

void UQuestSubsystem::BroadcastGlobalQuestEvent(FGameplayTag EventTag, int32 Amount)
{
	UE_LOG(LogTemp, Warning, TEXT("GLOBAL QUEST EVENT FIRED! EventTag: %s | Amount: %d "), *EventTag.ToString(), Amount);
	OnGlobalQuestEvent.Broadcast(EventTag, Amount);
}

void UQuestSubsystem::BroadcastItemCollected(UPrimaryDataAsset* ItemData, FGameplayTag ItemTag, int32 Amount)
{
	UE_LOG(LogTemp, Warning, TEXT("ITEM COLLECTED EVENT FIRED! ItemTag: %s | Amount: %d "), *ItemTag.ToString(), Amount);
	OnQuestItemCollected.Broadcast(ItemData, ItemTag, Amount);
}

void UQuestSubsystem::BroadcastWorldInteractable(FGameplayTag InteractTag, AActor* Interactor)
{
	UE_LOG(LogTemp, Warning, TEXT("WORLD INTERACT EVENT FIRED! InteractTag: %s "), *InteractTag.ToString());
	OnQuestInteractable.Broadcast(InteractTag, Interactor);
}

// Helper functions

bool UQuestSubsystem::IsQuestActive(FGameplayTag QuestTag) const
{
	return ActiveQuestInstances.Contains(QuestTag);
}

bool UQuestSubsystem::IsQuestCompleted(FGameplayTag QuestTag) const
{
	return CompletedQuests.HasTag(QuestTag);
}