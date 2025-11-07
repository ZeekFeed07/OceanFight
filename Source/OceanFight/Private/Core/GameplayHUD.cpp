#include "Core/GameplayHUD.h"
#include "Blueprint/UserWidget.h"
#include "Declarations.h"

DEFINE_LOG_CATEGORY(LogHUDInfo);

AGameplayHUD::AGameplayHUD()
{
	PrimaryActorTick.bCanEverTick = true;

	LoadData();
}

void AGameplayHUD::InitWidget(APlayerController* PC)
{
	if (!PC)
	{
		UE_LOG(LogHUDInfo, Error, TEXT("Owner PlayerController is incorrect"));
		return;
	}
	if (!WidgetClass)
	{
		UE_LOG(LogHUDInfo, Error, TEXT("WidgetClass is null"));
		return;
	}
	if (WidgetInstance && WidgetInstance->IsInViewport()) return;

	WidgetInstance = CreateWidget<UUserWidget>(PC, WidgetClass);
	if (!WidgetInstance)
	{
		UE_LOG(LogHUDInfo, Error, TEXT("WidgetInstance is incorrect"));
		return;
	}
	WidgetInstance->AddToViewport(0);
}

bool AGameplayHUD::LoadData()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> WBP_GameplayClass_Finder(*WBP_GameplayClass_Path);
	if (!WBP_GameplayClass_Finder.Succeeded())
	{
		UE_LOG(LogHUDInfo, Error, TEXT("Cannot find WBP_Gameplay class"));
		return false;
	}

	WidgetClass = WBP_GameplayClass_Finder.Class;
	return true;
}