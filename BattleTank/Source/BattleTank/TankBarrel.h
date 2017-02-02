// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent)) //, hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float speed);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float maxDegreePerSecond = 5.f;

	UPROPERTY(EditAnywhere, Category = Setup)
		float maxElevation = 40.f;

	UPROPERTY(EditAnywhere, Category = Setup)
		float minElevation = 0.f;
};
