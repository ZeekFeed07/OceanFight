#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "GameplayPC.generated.h"

UCLASS()
class OCEANFIGHT_API AGameplayPC : public APlayerController
{
	GENERATED_BODY()
public:
	AGameplayPC();
public:
	virtual void Tick(float DeltaSeconds) override;
protected:
	virtual void BeginPlay() override;

	virtual bool LoadData();

	virtual bool CastBaseClasses();

	virtual void SetupMode();
private:

public:
protected:
	TObjectPtr<class AGameplayPawn> Pawn	= nullptr;
	TObjectPtr<class AGameplayHUD> HUD		= nullptr;
private:
};
