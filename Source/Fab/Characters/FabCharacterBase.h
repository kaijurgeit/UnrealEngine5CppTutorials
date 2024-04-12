﻿// Fab by Kai Jurgeit

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "FabCharacterBase.generated.h"

class UGameplayAbility;
class UFabAbilitySystemComponent;
class UFabAttributeSet;
class UGameplayEffect;

UCLASS()
class FAB_API AFabCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AFabCharacterBase();
	//~IAbilitySystemInterface interface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~End of IAbilitySystemInterface interface
	virtual UFabAttributeSet* GetAttributeSet() const;

protected:
	void GiveDefaultAbilities();
	void InitDefaultAttributes() const;
		
	UPROPERTY()
	TObjectPtr<UFabAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UFabAttributeSet> AttributeSet;

	UPROPERTY(EditDefaultsOnly, Category = "Ability")
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;
	
	UPROPERTY(EditDefaultsOnly, Category = "Ability")
	TSubclassOf<UGameplayEffect> DefaultAttributeEffect;
};