// Fab by Kai Jurgeit


#include "FabAbilitySystemComponent.h"


UFabAbilitySystemComponent::UFabAbilitySystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	SetIsReplicated(true);
}

void UFabAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

