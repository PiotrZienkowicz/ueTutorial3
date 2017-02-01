// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTankAimingComponent();

	void SetBarrelReference(UStaticMeshComponent* barrelToSet);

	void AimAt(FVector hitLocation, float lunchSpeed);
		
private:
	UStaticMeshComponent* barrel = nullptr;
	
	void MoveBarrel(FVector aimDirection);
};
