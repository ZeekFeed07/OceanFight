#include "GameManager2D.h"
#include "Declarations.h"

UGameManager2D::UGameManager2D()
{
}

void UGameManager2D::InitGame()
{
	PrepareFields();
	SetupGameRule();
}

void UGameManager2D::AddShip(FShip Ship, AController* PlayerPtr)
{
}

void UGameManager2D::SetupPlayers(AController* NewPlayer, AController* NewEnemy)
{
	if (!NewPlayer && !NewEnemy)
	{
		UE_LOG(LogGameplayInfo, Error, TEXT("Player or Enemy is icorrect"));
		return;
	}
	Player	= NewPlayer;
	Enemy	= NewEnemy;
}

void UGameManager2D::PrepareFields()
{
	PlayerField.SetNum(10);
	EnemyField.SetNum(10);
	for (int32 i = 0; i < 10; ++i)
	{
		PlayerField[i].SetNum(10);
		EnemyField[i].SetNum(10);
	}
}

void UGameManager2D::SetupGameRule()
{
	GameRule.Add(EShipSize::ONE, 4);
	GameRule.Add(EShipSize::TWO, 3);
	GameRule.Add(EShipSize::THREE, 2);
	GameRule.Add(EShipSize::FOUR, 1);
}
