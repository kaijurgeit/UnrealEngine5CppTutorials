// Fab by Kai Jurgeit

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "FabAbilitySystemComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FAB_API UFabAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UFabAbilitySystemComponent();

protected:
	virtual void BeginPlay() override;
};