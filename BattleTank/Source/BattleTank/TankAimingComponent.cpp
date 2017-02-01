#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"


UTankAimingComponent::UTankAimingComponent()
{
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* barrelToSet)
{
	barrel = barrelToSet;
}

void UTankAimingComponent::AimAt(FVector hitLocation, float lunchSpeed)
{
	if (barrel)
	{
		FVector outLunchVelocity;
		FVector startLocation = barrel->GetSocketLocation(FName("Projectile"));
		bool bAimSolution = UGameplayStatics::SuggestProjectileVelocity(
			GetWorld(),
			outLunchVelocity,
			startLocation,
			hitLocation,
			lunchSpeed,
			false,
			0,
			0,
			ESuggestProjVelocityTraceOption::DoNotTrace);

		if (bAimSolution)
		{
			FVector aimDirection = outLunchVelocity.GetSafeNormal();
			MoveBarrel(aimDirection);
		}
		else
			UE_LOG(LogTemp, Warning, TEXT("%f No solution found"), GetWorld()->GetTimeSeconds());
	}
}

void UTankAimingComponent::MoveBarrel(FVector aimDirection)
{
	FRotator barrelRotation = barrel->GetForwardVector().Rotation();
	FRotator aimRotation = aimDirection.Rotation();

	FRotator deltaRotation = aimRotation - barrelRotation;

	barrel->Elevate(5);


	UE_LOG(LogTemp, Warning, TEXT("AimRotator: %s"), *(aimRotation.ToString()));
}

