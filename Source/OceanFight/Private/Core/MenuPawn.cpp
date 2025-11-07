#include "Core/MenuPawn.h"

AMenuPawn::AMenuPawn()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AMenuPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMenuPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMenuPawn::BeginPlay()
{
	Super::BeginPlay();
	
}
