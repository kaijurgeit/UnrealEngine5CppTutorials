// Fab by Kai Jurgeit


#include "PlayerCharacter.h"
#include "AbilitySystem/FabAbilitySystemComponent.h"
#include "AbilitySystem/FabAttributeSet.h"
#include "Player/FabPlayerState.h"
#include "UI/FabHUD.h"


APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	InitAbilitySystemComponent();
	GiveDefaultAbilities();
	InitDefaultAttributes();
	InitHUD();
}

void APlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	InitAbilitySystemComponent();
	InitDefaultAttributes();
	InitHUD();
}

void APlayerCharacter::InitAbilitySystemComponent()
{
	AFabPlayerState* FabPlayerState = GetPlayerState<AFabPlayerState>();
	check(FabPlayerState);
	AbilitySystemComponent =  CastChecked<UFabAbilitySystemComponent>(
		FabPlayerState->GetAbilitySystemComponent());
	AbilitySystemComponent->InitAbilityActorInfo(FabPlayerState, this);
	AttributeSet = FabPlayerState->GetAttributeSet();
}

void APlayerCharacter::InitHUD() const
{
	if(const APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if(AFabHUD* FabHUD = Cast<AFabHUD>(PlayerController->GetHUD()))
		{
			FabHUD->Init();
		}
	}
}