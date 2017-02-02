// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float speed)
{
	speed = FMath::Clamp<float>(speed, -1, 1);

	auto elevationChange = speed * maxDegreePerSecond * GetWorld()->DeltaTimeSeconds;

	auto rawNewElevation = RelativeRotation.Pitch + elevationChange;

	float elevation = FMath::Clamp(rawNewElevation, minElevation, maxElevation);
	SetRelativeRotation(FRotator(elevation, 0,0));

}
