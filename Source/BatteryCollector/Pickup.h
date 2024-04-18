// Fill out your copyright notice in the Description page of Project Settings.
//Code contributors: Celina Oseguera


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Accessor function
	// Return the mesh for the pickup
	FORCEINLINE class UStaticMeshComponent* GetMesh() const {return PickupMesh;}
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	//Accessor functions for state of pickup ie. active or not
	UFUNCTION(BlueprintPure, Category = "Pickup")
	bool IsActive();

	UFUNCTION(BlueprintCallable, Category = "Pickup")
	void SetActive(bool NewPickupState);

	// Function to call when the pickup is collected
	UFUNCTION(BlueprintNativeEvent)
	void WasCollected();
	virtual void WasCollected_Implementation();

protected: 
	// True when the pickup can be used, and false when pickup is deativated
	bool bIsActive;

private:
// Static mesh to represent the pickup in the level//
UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
class UStaticMeshComponent* PickupMesh;

};
