#include "Core/GameplayPC.h"
#include "Core/GameplayPawn.h"
#include "Core/GameplayHUD.h"
#include "GameManager2D.h"
#include "Declarations.h"

DEFINE_LOG_CATEGORY(LogGameplayInfo)

AGameplayPC::AGameplayPC()
{
	PrimaryActorTick.bCanEverTick = true;

	LoadData();
}

void AGameplayPC::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AGameplayPC::BeginPlay()
{
	Super::BeginPlay();

	CastBaseClasses();
	SetupMode();

	HUD->InitWidget(this);
}

bool AGameplayPC::LoadData()
{
	return true;
}

bool AGameplayPC::CastBaseClasses()
{
	if (!GetWorld())
	{
		UE_LOG(LogGameplayInfo, Error, TEXT("World is invalid"));
		return false;
	}
	Pawn = Cast<AGameplayPawn>(GetPawn());
	if (!Pawn)
	{
		UE_LOG(LogGameplayInfo, Error, TEXT("Pawn is invalid"));
		return false;
	}
	HUD = Cast<AGameplayHUD>(GetHUD());
	if (!HUD)
	{
		UE_LOG(LogGameplayInfo, Error, TEXT("HUD is invalid"));
		return false;
	}
	return true;
}

void AGameplayPC::SetupMode()
{
	FInputModeGameAndUI Mode;
	Mode.SetHideCursorDuringCapture(false);
	SetInputMode(Mode);
	bShowMouseCursor = true;
}