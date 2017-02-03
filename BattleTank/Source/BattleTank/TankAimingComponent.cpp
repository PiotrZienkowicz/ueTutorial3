#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"


UTankAimingComponent::UTankAimingComponent()
{
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* barrelToSet)
{
	barrel = barrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret* turretToSet)
{
	turret = turretToSet;
}

void UTankAimingComponent::AimAt(FVector hitLocation, float lunchSpeed)
{
	UE_LOG(LogTemp, Warning, TEXT("Test"));

	if (barrel && turret)
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

	barrel->Elevate(deltaRotation.Pitch);
	turret->Rotate(deltaRotation.Yaw);
}

