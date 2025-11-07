#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "MenuPlayerController.generated.h"

UCLASS()
class OCEANFIGHT_API AMenuPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AMenuPlayerController();
public:
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable)
	virtual void StartGame();

	UFUNCTION(BlueprintCallable)
	virtual void Quit();
protected:
	virtual void BeginPlay() override;

	virtual bool LoadData();
	
	virtual bool CastBaseClasses();
public:
	const FName GameplayLevel = TEXT("L_Gameplay");

protected:
	TObjectPtr<class AMenuPawn> Pawn	= nullptr;
	TObjectPtr<class AMenuHUD> HUD		= nullptr;
};
