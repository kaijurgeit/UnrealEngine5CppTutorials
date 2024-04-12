// Fab by Kai Jurgeit

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FabHUD.generated.h"

class UAttributesWidget;
/**
 * 
 */
UCLASS()
class FAB_API AFabHUD : public AHUD
{
	GENERATED_BODY()
public:
	void Init();
	
protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UAttributesWidget> AttributeWidgetClass;

private:
	UPROPERTY()
	TObjectPtr<UAttributesWidget> AttributeWidget;
};
