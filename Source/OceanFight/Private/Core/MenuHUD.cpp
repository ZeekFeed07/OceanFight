#include "Core/MenuHUD.h"
#include "Blueprint/UserWidget.h"
#include "Declarations.h"

DEFINE_LOG_CATEGORY(LogMainMenu)

AMenuHUD::AMenuHUD()
{
	PrimaryActorTick.bCanEverTick = false;

	LoadOData();
}

void AMenuHUD::BeginPlay()
{
	Super::BeginPlay();


}

bool AMenuHUD::LoadOData()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> WBP_MainMenuClass_Finder(*WBP_MainMenuClass_Path);
	if (!WBP_MainMenuClass_Finder.Succeeded())
	{
		UE_LOG(LogMainMenu, Error, TEXT("Cannot find WBP_MainMenu class"));
		return false;
	}

	WidgetClass = WBP_MainMenuClass_Finder.Class;

	return true;
}

void AMenuHUD::InitWidget(APlayerController* PC)
{
	if (!PC)
	{
		UE_LOG(LogMainMenu, Error, TEXT("Owner PlayerController is incorrect"));
		return;
	}
	if (!WidgetClass)
	{
		UE_LOG(LogMainMenu, Error, TEXT("WidgetClass is null"));
		return;
	}
	if (WidgetInstance && WidgetInstance->IsInViewport()) return;
	
	WidgetInstance = CreateWidget<UUserWidget>(PC, WidgetClass);
	if (!WidgetInstance)
	{
		UE_LOG(LogMainMenu, Error, TEXT("WidgetInstance is incorrect"));
		return;
	}
	WidgetInstance->AddToViewport(0);
}