// Fab by Kai Jurgeit

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "FabPlayerState.generated.h"

class UFabAbilitySystemComponent;
class UFabAttributeSet;

UCLASS()
class FAB_API AFabPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AFabPlayerState();
	//~IAbilitySystemInterface interface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~End of IAbilitySystemInterface interface
	virtual UFabAttributeSet* GetAttributeSet() const;

protected:	
	UPROPERTY()
	TObjectPtr<UFabAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UFabAttributeSet> AttributeSet;
};