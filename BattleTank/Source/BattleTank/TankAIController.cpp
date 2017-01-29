// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* posessedTank = GetControlledTank();
	if (posessedTank != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controlled tank is %s"), *(posessedTank->GetName()))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI couldn't find a tank"))
	}
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(this->GetPawn());
}