// Fab by Kai Jurgeit


#include "FabCharacterBase.h"
#include "AbilitySystem/FabAbilitySystemComponent.h"


AFabCharacterBase::AFabCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

UAbilitySystemComponent* AFabCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UFabAttributeSet* AFabCharacterBase::GetAttributeSet() const
{
	return AttributeSet;
}

void AFabCharacterBase::GiveDefaultAbilities()
{
	check(AbilitySystemComponent);
	if(!HasAuthority()) return;
	
	for(TSubclassOf<UGameplayAbility> AbilityClass : DefaultAbilities)
	{
		const FGameplayAbilitySpec AbilitySpec(AbilityClass, 1);
		AbilitySystemComponent->GiveAbility(AbilitySpec);
	}
}

void AFabCharacterBase::InitDefaultAttributes() const
{
	if(!AbilitySystemComponent || !DefaultAttributeEffect) { return; }
	
	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	const FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributeEffect, 1.f, EffectContext);

	if(SpecHandle.IsValid())
	{
		AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());			
	}
}
