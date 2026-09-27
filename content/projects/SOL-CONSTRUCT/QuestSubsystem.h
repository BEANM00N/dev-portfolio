#pragma once

#include "CoreMinimal.h"
#include "flecs.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameplayTagContainer.h"
#include "Engine/DataTable.h"
#include "Engine/DataAsset.h"
#include "QuestSubsystem.generated.h"

class UQuestStep_Base;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestStepStarted, FGameplayTag, QuestTag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestStepCompleted, FGameplayTag, QuestTag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGlobalQuestEvent, FGameplayTag, EventTag, int32, Amount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnQuestItemCollected, UPrimaryDataAsset*, ItemData, FGameplayTag, ItemTag, int32, Amount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnQuestInteractable, FGameplayTag, InteractTag, AActor*, Interactor);


USTRUCT(BlueprintType)
struct FRewardStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Reward")
	UPrimaryDataAsset* Item = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Reward")
	int32 Amount = 0;
};

UENUM(BlueprintType)
enum class EObjectiveType : uint8
{
	Interact UMETA(DisplayName = "Interact"),
	Kill UMETA(DisplayName = "Kill"), 
	Collect UMETA(DisplayName = "Collect"),
};

USTRUCT(BlueprintType)
struct FQuestObjective
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Data")
	FText ObjectiveDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Data")
	EObjectiveType ObjectiveType = EObjectiveType::Interact;

	// Used for Kill objectives, or general tag based tracking
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Data")
	FGameplayTag TargetTag;

	// Only appears in the Data Table if 'Collect' is selected
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Data", meta=(EditCondition="ObjectiveType == EObjectiveType::Collect", EditConditionHides))
	UPrimaryDataAsset* TargetItemAsset = nullptr;

	// Only appears in the Data Table if 'Interact' is selected
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Data", meta=(EditCondition="ObjectiveType == EObjectiveType::Interact", EditConditionHides))
	TSubclassOf<AActor> TargetActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Data")
	int32 RequiredAmount = 1;
};

USTRUCT(BlueprintType)
struct FQuestDatabase : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Data")
	FText StepDescription; 
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Data")
	TArray<FQuestObjective> Objectives; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Data")
	FGameplayTag CurrentStepTag;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Data")
	FGameplayTagContainer PrerequisiteQuests;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Data")
	FGameplayTag NextStepTag;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Data")
	FGameplayTag QuestLineTag;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Data")
	TArray<FRewardStruct> Rewards;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Data")
	TSubclassOf<UQuestStep_Base> CustomStepLogic; 
};

// Save state struct. NOT USED YET. Just making sure its here for future implementation
USTRUCT(BlueprintType)
struct FActiveQuestSaveData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Quest Save Data")
	FGameplayTag QuestStepTag;

	UPROPERTY(BlueprintReadWrite, Category = "Quest Save Data")
	TArray<int32> ObjectiveProgress;
};


UCLASS()
class UQuestSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	// Map the Step Tag to the Instanced UObject managing it
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Quests|Active")
	TMap<FGameplayTag, UQuestStep_Base*> ActiveQuestInstances;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Quests|Active")
	FGameplayTagContainer CompletedQuests;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Quests|Active")
	UDataTable* QuestDataTableAsset;

	UFUNCTION(BlueprintCallable, Category = "Quests|Setup")
	void InitializeQuestSystem(UDataTable* InDataTable);
	
	UFUNCTION(BlueprintCallable, Category = "Quests")
	void StartQuestStep(FGameplayTag StartingTag);
	
	UFUNCTION(BlueprintCallable, Category = "Quests") 	// Called by UQuestStep_Base when it finishes
	void FinishQuestStep(FGameplayTag StepTag);
	
	UFUNCTION(BlueprintCallable, Category = "Quests|Save")
	TArray<FActiveQuestSaveData> ExtractSaveData() const;

	UFUNCTION(BlueprintCallable, Category = "Quests|Save")
	void RestoreSaveData(const TArray<FActiveQuestSaveData>& SavedData);
	
	UFUNCTION(BlueprintCallable, Category = "Quests|Broadcast") 
	void BroadcastGlobalQuestEvent(FGameplayTag EventTag, int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Quests|Broadcast")
	void BroadcastItemCollected(UPrimaryDataAsset* ItemData, FGameplayTag ItemTag, int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Quests|Broadcast")
	void BroadcastWorldInteractable(FGameplayTag InteractTag, AActor* Interactor);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Quests|Queries")
	bool IsQuestActive(FGameplayTag QuestTag) const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Quests|Queries")
	bool IsQuestCompleted(FGameplayTag QuestTag) const;


	
	UPROPERTY(BlueprintAssignable, Category = "Quests|Events")
	FOnQuestStepStarted OnQuestStepStarted;

	UPROPERTY(BlueprintAssignable, Category = "Quests|Events")
	FOnQuestStepCompleted OnQuestStepCompleted;

	UPROPERTY(BlueprintAssignable, Category= "Quests|Events")
	FOnGlobalQuestEvent OnGlobalQuestEvent;

	UPROPERTY(BlueprintAssignable, Category= "Quests|Events")
	FOnQuestItemCollected OnQuestItemCollected;

	UPROPERTY(BlueprintAssignable, Category= "Quests|Events")
	FOnQuestInteractable OnQuestInteractable;
};