// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ATank* posessedTank = GetControlledTank();
	if (posessedTank != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Controlled tank is %s"), *(posessedTank->GetName()))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Couldn't find a tank"))

	}

}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(this->GetPawn());
}