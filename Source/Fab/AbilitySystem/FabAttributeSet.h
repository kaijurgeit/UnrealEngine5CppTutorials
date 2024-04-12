// Fab by Kai Jurgeit

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "FabAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

#define NUMERIC_VALUE(AttributeSetName, PropertyName) \
	AttributeSetName->Get##PropertyName##Attribute().GetNumericValue(AttributeSetName)

/**
 * 
 */
UCLASS()
class FAB_API UFabAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UFabAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Ability | Gameplay Attribute")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UFabAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Ability | Gameplay Attribute")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UFabAttributeSet, MaxHealth);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Stamina, Category = "Ability | Gameplay Attribute")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UFabAttributeSet, Stamina);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStamina, Category = "Ability | Gameplay Attribute")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UFabAttributeSet, MaxStamina);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Strength, Category = "Ability | Gameplay Attribute")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UFabAttributeSet, Strength);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStrength, Category = "Ability | Gameplay Attribute")
	FGameplayAttributeData MaxStrength;
	ATTRIBUTE_ACCESSORS(UFabAttributeSet, MaxStrength);
	
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	
	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldStamina) const;
	
	UFUNCTION()
	void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const;
	
	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStamina) const;
	
	UFUNCTION()
	void OnRep_MaxStrength(const FGameplayAttributeData& OldMaxStamina) const;
};
