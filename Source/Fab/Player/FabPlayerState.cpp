// Fab by Kai Jurgeit


#include "FabPlayerState.h"
#include "AbilitySystem/FabAbilitySystemComponent.h"
#include "AbilitySystem/FabAttributeSet.h"


AFabPlayerState::AFabPlayerState()
{
	NetUpdateFrequency = 100.f;
	
	AbilitySystemComponent = CreateDefaultSubobject<UFabAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AttributeSet = CreateDefaultSubobject<UFabAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AFabPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UFabAttributeSet* AFabPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}