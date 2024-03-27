// Fill out your copyright notice in the Description page of Project Settings.


#include "BatteryPickup.h"

// Set default vlaues
ABatteryPickup::ABatteryPickup()
{
	GetMesh()->SetSimulatePhysics(true);
}

void ABatteryPickup::WasCollected_Implementation() 
{
	// Use base pickup behavior
	Super::WasCollected_Implementation();
	// Destroy battery
	Destroy();
}