// Custom Viewport Client to Override the Background
class FMyPreviewViewportClient : public FEditorViewportClient
{
public:
    FMyPreviewViewportClient(FPreviewScene* InPreviewScene)
        : FEditorViewportClient(nullptr, InPreviewScene)
    {
    }

    // Overrides the default engine color with matching UI Hex
    virtual FLinearColor GetBackgroundColor() const override
    {
        return FColor::FromHex(TEXT("#131313"));
    }
};

// ... inside SMyCustomViewport ::MakeEditorViewportClient() ...
MyViewportClient = MakeShareable(new FMyPreviewViewportClient(PreviewScene.Get()));
MyViewportClient->bSetListenerPosition = false;
MyViewportClient->SetRealtime(true);