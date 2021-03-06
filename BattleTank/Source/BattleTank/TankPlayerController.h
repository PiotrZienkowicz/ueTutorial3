// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // must be the last

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
		
private:
	UPROPERTY(EditDefaultsOnly)
	float crossHairXLocation = 0.5f;
	UPROPERTY(EditDefaultsOnly)
	float crossHairYLocation = 0.33333f;
	UPROPERTY(EditDefaultsOnly)
	float maxRange = 10000.0f;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	ATank* GetControlledTank() const;
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation( FVector &) const;

	bool GetLookDirection(FVector2D screenLocation, FVector &lookDirection) const;

	bool GetVectorLookLocation(FVector lookDirection, FVector &hitLocation) const;
};
