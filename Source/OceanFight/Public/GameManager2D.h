#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "GameManager2D.generated.h"

UENUM(BlueprintType)
enum class ECellState : uint8
{
	ClOSED,
	EMPTY,
	PLACED,
	DEADZONE,
	DESTROYED
};

UENUM(BlueprintType)
enum class EShipSize : uint8
{
	ONE,
	TWO,
	THREE,
	FOUR
};


UENUM(BlueprintType)
enum class EShipDirection : uint8
{
	TOP,
	RIGHT,
	BOTTOM,
	LEFT
};

USTRUCT(BlueprintType)
struct FCell
{
	GENERATED_BODY()
	ECellState State = ECellState::ClOSED;
};

USTRUCT(BlueprintType)
struct FShip
{
	GENERATED_BODY()
	EShipSize		Size		= EShipSize::ONE;
	EShipDirection	Direction	= EShipDirection::TOP;
};

UCLASS()
class OCEANFIGHT_API UGameManager2D : public UObject
{
	GENERATED_BODY()
public:
	UGameManager2D();
public:
	virtual void InitGame();
	virtual void AddShip(FShip Ship, AController* PlayerPtr);
	virtual void SetupPlayers(AController* NewPlayer, AController* NewEnemy);
protected:
	virtual void PrepareFields();
	virtual void SetupGameRule();
private:	
	TObjectPtr<AController> Player;
	TObjectPtr<AController> Enemy;
	TArray<TArray<FCell>> PlayerField;
	TArray<TArray<FCell>> EnemyField;

	TMap<EShipSize, int32> GameRule;
};
