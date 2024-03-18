// Fab by Kai Jurgeit

#pragma once

#include "CoreMinimal.h"
#include "FabCharacterBase.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class FAB_API APlayerCharacter : public AFabCharacterBase
{
	GENERATED_BODY()

public:
	APlayerCharacter();
	virtual void Tick(float DeltaSeconds) override;

protected:
	virtual void BeginPlay() override;
};