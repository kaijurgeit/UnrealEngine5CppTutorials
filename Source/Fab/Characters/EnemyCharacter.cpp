// Fab by Kai Jurgeit


#include "EnemyCharacter.h"
#include "AbilitySystem/FabAbilitySystemComponent.h"
#include "AbilitySystem/FabAttributeSet.h"


AEnemyCharacter::AEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	AbilitySystemComponent = CreateDefaultSubobject<UFabAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	AttributeSet = CreateDefaultSubobject<UFabAttributeSet>("AttributeSet");
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	GiveDefaultAbilities();
	InitDefaultAttributes();
}

