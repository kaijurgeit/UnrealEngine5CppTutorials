// Fab by Kai Jurgeit

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FabCharacterBase.generated.h"

UCLASS()
class FAB_API AFabCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AFabCharacterBase();

protected:
	virtual void BeginPlay() override;
};