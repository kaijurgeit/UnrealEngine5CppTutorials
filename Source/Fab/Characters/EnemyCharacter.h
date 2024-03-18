// Fab by Kai Jurgeit

#pragma once

#include "CoreMinimal.h"
#include "FabCharacterBase.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class FAB_API AEnemyCharacter : public AFabCharacterBase
{
	GENERATED_BODY()

public:
	AEnemyCharacter();

protected:
	virtual void BeginPlay() override;
};