#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameplayHUD.generated.h"

UCLASS()
class OCEANFIGHT_API AGameplayHUD : public AHUD
{
	GENERATED_BODY()
public:
	AGameplayHUD();
public:
	virtual void InitWidget(APlayerController* PC);
protected:
	virtual bool LoadData();
private:

public:
	const FString WBP_GameplayClass_Path = TEXT("/Game/OceanFight/DEV/UI/WBP_Gameplay.WBP_Gameplay_C");
protected:
private:
	TSubclassOf<UUserWidget> WidgetClass	= nullptr;
	TObjectPtr<UUserWidget> WidgetInstance	= nullptr;
};
