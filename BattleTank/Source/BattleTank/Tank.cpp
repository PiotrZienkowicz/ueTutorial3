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
	PrimaryActorTick.bCanEverTick = true;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming component"));
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
}

void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
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
	if (barrel)
	{
		UE_LOG(LogTemp, Warning, TEXT("%f - Fire"), GetWorld()->GetTimeSeconds());
		FVector location = barrel->GetSocketLocation(FName("Projectile"));
		GetWorld()->SpawnActor<AProjectile>(projectileBlueprint, location, FRotator(0, 0, 0));
	}

}

