// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Pojectile.h"


// Sets default values
APojectile::APojectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APojectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APojectile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

