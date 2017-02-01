#include "BattleTank.h"
#include "Tank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true;
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

void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(this->GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) return;
	else
	{
		FVector hitLocation = FVector::ZeroVector;
		if (GetSightRayHitLocation(hitLocation))
		{
			GetControlledTank()->AimAt(hitLocation);
		}
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & hitLocation) const
{
	int32 viewPortX, viewPortY;
	GetViewportSize(viewPortX, viewPortY);

	FVector2D screenLocation(viewPortX * crossHairXLocation, viewPortY * crossHairYLocation);

	FVector lookDirection;
	if (GetLookDirection(screenLocation, lookDirection))
	{
		GetVectorLookLocation(lookDirection, hitLocation);
		return true;
	}
	else
		return false;

}


bool ATankPlayerController::GetLookDirection(FVector2D screenLocation, FVector &lookDirection) const
{
	FVector worldLocation;
	return DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, worldLocation, lookDirection);
}

bool ATankPlayerController::GetVectorLookLocation(FVector lookDirection, FVector &hitLocation) const
{
	FHitResult hit;
	FVector startLocation = PlayerCameraManager->GetCameraLocation();
	FVector endLocation = startLocation + (lookDirection * maxRange);
	if (GetWorld()->LineTraceSingleByChannel(hit, startLocation, endLocation, ECC_Visibility))
	{
		hitLocation = hit.Location;
		return true;
	}
	else
	{
		hitLocation = FVector::ZeroVector;
		return false;
	}
}
