#include "Core/GameplayPawn.h"

AGameplayPawn::AGameplayPawn()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AGameplayPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGameplayPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGameplayPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

