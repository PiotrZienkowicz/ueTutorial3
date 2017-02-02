// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"

void UTankTurret::Rotate(float speed)
{
	speed = FMath::Clamp<float>(speed, -1, 1);

	auto rotationChange = speed * maxDegreePerSecond * GetWorld()->DeltaTimeSeconds;

	auto rawNewRotation = RelativeRotation.Yaw + rotationChange;

	SetRelativeRotation(FRotator(0, rawNewRotation, 0));

	UE_LOG(LogTemp, Warning, TEXT("Trying rotation: %f"), rawNewRotation);

}
