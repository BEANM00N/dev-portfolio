void UModelPreviewWidget::ApplyMeshAsset()
{
#if WITH_EDITOR
    // Safely cast the generic UObject parameter assigned via the SinglePropertyView
    if (UStaticMesh* SM = Cast<UStaticMesh>(PreviewMeshAsset))
    {
        SetStaticMesh(SM);
    }
    else if (USkeletalMesh* SKM = Cast<USkeletalMesh>(PreviewMeshAsset))
    {
        SetSkeletalMesh(SKM);
    }
    else 
    {
        SetStaticMesh(nullptr);
        SetSkeletalMesh(nullptr);
    }
#endif
}