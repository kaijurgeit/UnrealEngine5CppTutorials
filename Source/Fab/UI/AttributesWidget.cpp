// Fab by Kai Jurgeit


#include "AttributesWidget.h"
#include "AbilitySystem/FabAttributeSet.h"
#include "Player/FabPlayerState.h"

void UAttributesWidget::BindToAttributes()
{
	const AFabPlayerState* FabPlayerState = Cast<AFabPlayerState>(GetOwningPlayerState());
	if(!FabPlayerState) return;
	
	UAbilitySystemComponent* ASC = FabPlayerState->GetAbilitySystemComponent();
	const UFabAttributeSet* FabAS = FabPlayerState->GetAttributeSet();

	// Initial Attributes
	HealthPercent = NUMERIC_VALUE(FabAS, Health) / NUMERIC_VALUE(FabAS, MaxHealth);
	StaminaPercent = NUMERIC_VALUE(FabAS, Stamina) / NUMERIC_VALUE(FabAS, MaxStamina);
	
	// Attribute Changes
	ASC->GetGameplayAttributeValueChangeDelegate(FabAS->GetHealthAttribute()).AddLambda(
	[this, FabAS](const FOnAttributeChangeData& Data)
	{
		HealthPercent = Data.NewValue / NUMERIC_VALUE(FabAS, MaxHealth);
	});
	
	ASC->GetGameplayAttributeValueChangeDelegate(FabAS->GetStaminaAttribute()).AddLambda(
	[this, FabAS](const FOnAttributeChangeData& Data)
	{
		StaminaPercent = Data.NewValue / NUMERIC_VALUE(FabAS, MaxStamina);;
	});
}