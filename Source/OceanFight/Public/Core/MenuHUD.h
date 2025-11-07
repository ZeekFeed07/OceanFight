#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MenuHUD.generated.h"

UCLASS()
class OCEANFIGHT_API AMenuHUD : public AHUD
{
	GENERATED_BODY()
public:
	AMenuHUD();
public:
	virtual void InitWidget(APlayerController* PC);
protected:
	virtual void BeginPlay() override;

	virtual bool LoadOData();
private:

public:
	const FString WBP_MainMenuClass_Path = TEXT("/Game/OceanFight/DEV/UI/WBP_MainMenu.WBP_MainMenu_C");

private:
	TSubclassOf<UUserWidget> WidgetClass	= nullptr;
	TObjectPtr<UUserWidget> WidgetInstance	= nullptr;
};
