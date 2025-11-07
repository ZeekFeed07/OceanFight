#include "Core/MenuGM.h"
#include "Core/MenuPlayerController.h"
#include "Core/MenuPawn.h"
#include "Core/MenuHUD.h"

AMenuGM::AMenuGM()
{
	PlayerControllerClass	= AMenuPlayerController::StaticClass();
	DefaultPawnClass		= AMenuPawn::StaticClass();
	HUDClass				= AMenuHUD::StaticClass();
}
	