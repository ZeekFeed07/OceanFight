#include "Core/MainGM.h"
#include "Core/GameplayPC.h"
#include "Core/GameplayPawn.h"
#include "Core/GameplayHUD.h"

AMainGM::AMainGM()
{
	PlayerControllerClass	= AGameplayPC::StaticClass();
	DefaultPawnClass		= AGameplayPawn::StaticClass();
	HUDClass				= AGameplayHUD::StaticClass();
}
