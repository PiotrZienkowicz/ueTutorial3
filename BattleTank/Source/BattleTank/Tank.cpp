#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "Tank.h"


void ATank::SetBarrelReference(UTankBarrel* barrelToSet)
{
	barrel = barrelToSet;
	TankAimingComponent->SetBarrelReference(barrelToSet);
}

void ATank::SetTurretReference(UTankTurret* turretToSet)
{
	TankAimingComponent->SetTurretReference(turretToSet);
}

ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming component"));
}

void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank::AimAt(FVector hitLocation)
{
	TankAimingComponent->AimAt(hitLocation, lunchSpeed);
}

void ATank::Fire()
{
	bool isReloaded = ((GetWorld()->GetTimeSeconds() - lastFireTime) > reloadTimeInSeconds);
	if (barrel && isReloaded)
	{
		lastFireTime = GetWorld()->GetTimeSeconds();
		auto projectile = GetWorld()->SpawnActor<AProjectile>(
			projectileBlueprint, 
			barrel->GetSocketLocation(FName("Projectile")),
			barrel->GetSocketRotation(FName("Projectile"))
			);

		projectile->LunchProjectile(lunchSpeed);
	}

}

