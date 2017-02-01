#include "BattleTank.h"
#include "TankAimingComponent.h"


UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* barrelToSet)
{
	barrel = barrelToSet;
}

void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UTankAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

}

void UTankAimingComponent::AimAt(FVector hitLocation, float lunchSpeed)
{
	if (barrel)
	{
		FVector outLunchVelocity;
		FVector startLocation = barrel->GetSocketLocation(FName("Projectile"));

		if (UGameplayStatics::SuggestProjectileVelocity(
			GetWorld(),
			outLunchVelocity,
			startLocation,
			hitLocation,
			lunchSpeed,
			false,
			0,
			0,
			ESuggestProjVelocityTraceOption::DoNotTrace
		))
		{
			FVector aimDirection = outLunchVelocity.GetSafeNormal();
			UE_LOG(LogTemp, Warning, TEXT("Aiming at  %s"), *(aimDirection.ToString()));
		}
	}
	
}

