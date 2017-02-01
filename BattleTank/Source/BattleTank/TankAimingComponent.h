#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel* barrelToSet);

	void AimAt(FVector hitLocation, float lunchSpeed);
		
private:
	UTankBarrel* barrel = nullptr;
	
	void MoveBarrel(FVector aimDirection);
};
