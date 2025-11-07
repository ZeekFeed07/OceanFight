#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameplayPawn.generated.h"

UCLASS()
class OCEANFIGHT_API AGameplayPawn : public APawn
{
	GENERATED_BODY()

public:
	AGameplayPawn();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
