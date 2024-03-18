// Fab by Kai Jurgeit


#include "PlayerCharacter.h"

#include "FabMacros.h"


APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APlayerCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	SPHERE_TICK(GetActorLocation());
	LINE_TICK(GetActorLocation(), FVector(2200.f, 700.f, 150.f));
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("%s"), *FString(__FUNCTION__));
	UE_LOG(LogTemp, Warning, TEXT("PrimaryActorTick.bCanEverTick = %s"), PrimaryActorTick.bCanEverTick ? TEXT("true") : TEXT("false"));
	PRINT("Hello, %s", *FString(__FUNCTION__));
	FVector TargetLocation(2200.f, 700.f, 150.f);
	SPHERE(TargetLocation);
	LINE(GetActorLocation(), TargetLocation);
}

