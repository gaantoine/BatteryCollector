// Copyright Epic Games, Inc. All Rights Reserved.
//Code contributors: Celina Oseguera, Allen Antoine

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "Components/SphereComponent.h"
#include "BatteryCollectorCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class ABatteryCollectorCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	/** Collection sphere */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USphereComponent* CollectionSphere;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

public:
	ABatteryCollectorCharacter();

	// accessor function for intial power
	UFUNCTION(BlueprintPure, Category = "Power")
	float GetInitialPower();

	// accessor function for current power
	UFUNCTION(BlueprintPure,Category = "Power")
	float GetCurrentPower();

	// function to update the charcter's power
	//@param powerchange this is the amount to change power by, can be + or -
	UFUNCTION(BlueprintCallable, Category = "Power")
	void UpdatePower(float PowerChange);
	

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);
			

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// Called when we press a key to collect any pickups inside the CollectionSphere
	UFUNCTION(BlueprintCallable, Category = "Pickups")
	void CollectPickups();

	// To add mapping context
	virtual void BeginPlay();

	// the starting power level of character
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected))
	float InitialPower;

	/*Multiplier for character speed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected))
	float SpeedFactor;

	/*Speed when power level = 0 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected))
	float BaseSpeed;

	UFUNCTION(BlueprintImplementableEvent, Category = "Power")
	void PowerChangeEffect();

private:
	// Current power level of character
	UPROPERTY(VisibleAnywhere, Category = "Power")
	float CharacterPower;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	// Returns CollectionSphere subobject
	FORCEINLINE class USphereComponent* GetCollectionSphere() const { return CollectionSphere; }
};

