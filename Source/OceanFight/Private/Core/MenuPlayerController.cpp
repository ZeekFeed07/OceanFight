#include "Kismet/GameplayStatics.h"

#include "Core/MenuPlayerController.h"
#include "Core/MenuPawn.h"
#include "Core/MenuHUD.h"
#include "Declarations.h"

AMenuPlayerController::AMenuPlayerController()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AMenuPlayerController::Tick(float DeltaSeconds)
{
}

void AMenuPlayerController::StartGame()
{
	TObjectPtr<UWorld> World = GetWorld();

	if (World)
	{
		UGameplayStatics::OpenLevel(World, GameplayLevel);
		return;
	}
	UE_LOG(LogMainMenu, Error, TEXT("World is invalid"));
}

void AMenuPlayerController::Quit()
{
	UKismetSystemLibrary::QuitGame(this, this, EQuitPreference::Quit, true);
}

void AMenuPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (!CastBaseClasses()) return;

	HUD->InitWidget(this);

	FInputModeGameAndUI Mode;
	Mode.SetHideCursorDuringCapture(false);
	SetInputMode(Mode);
	bShowMouseCursor = true;
}

bool AMenuPlayerController::LoadData()
{
	return false;
}

bool AMenuPlayerController::CastBaseClasses()
{
	if (!GetWorld())
	{
		UE_LOG(LogMainMenu, Error, TEXT("World is invalid"));
		return false;
	}
	Pawn = Cast<AMenuPawn>(GetPawn());
	if (!Pawn)
	{
		UE_LOG(LogMainMenu, Error, TEXT("Pawn is invalid"));
		return false;
	}
	HUD = Cast<AMenuHUD>(GetHUD());
	if (!HUD)
	{
		UE_LOG(LogMainMenu, Error, TEXT("HUD is invalid"));
		return false;
	}
	return true;
}
