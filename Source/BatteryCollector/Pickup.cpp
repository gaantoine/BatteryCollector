// Fill out your copyright notice in the Description page of Project Settings.
//Code contributors: Celina Oseguera


#include "Pickup.h"
#include "BatteryCollector.h"


// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//All pickups start active
	bIsActive = true;

	//Create the static mesh component
	PickupMesh = CreateDefaultSubobject <UStaticMeshComponent> (TEXT("PickupMesh"));
	RootComponent = PickupMesh;
	
}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();
	
}
//Called every frame
void APickup::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);
}
// Returns active state
bool APickup::IsActive()
{
	return bIsActive;
}
//Sets active state
void APickup:: SetActive(bool NewPickupState)
{
	bIsActive = NewPickupState;
}

void APickup::WasCollected_Implementation()
{
	//Log a debug message
	FString PickupDebuggingString = GetName();
	UE_LOG(LogClass, Log, TEXT("You have collected %s"), *PickupDebuggingString);
}