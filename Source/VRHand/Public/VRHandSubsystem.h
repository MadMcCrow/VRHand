// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "InputCoreTypes.h"
#include "VRHandStructs.h"
#include "VRHandSubsystem.generated.h"

class UVRHandInputComponent;

/**
 * 
 */
UCLASS(Category="VRHand")
class VRHAND_API UVRHandSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()

	friend UVRHandInputComponent;

public:
	static FName VRInputComponentName;

	UVRHandSubsystem();

protected:

	/* ULocalPlayerSubsystem overrides */
	virtual void Initialize(FSubsystemCollectionBase & Collection) override;
	virtual void Deinitialize() override;
	/* \ ULocalPlayerSubsystem overrides */

public:


	/**
	 * 	@fn	BindControllerHandsEvents Bind axes to their relative functions
	 */
	UFUNCTION(BlueprintCallable)
	void BindControllerHandsEvents();

	/**
	 * 	@fn	Get Hand status for 
	 */
	UFUNCTION(BlueprintPure)
	FVRHandHandInfo GetHandStatus(EControllerHand Hand) const 
	{
		if (FVRHandHandInfo* HandInfo = GetHands().Find(Hand)) 
			return *HandInfo;
		return FVRHandHandInfo(); 
	}

	/**
	 * 	@fn	Get All Hands status
	 */
	UFUNCTION(BlueprintPure)
	TMap<EControllerHand, FVRHandHandInfo> GetHands() const { return PlayerHands; }

	UFUNCTION(BlueprintPure)
	class APlayerController* GetController() const {return Controller; }

	
protected:

	/**
	 * 	Create all the input Component we could find
	 */
	void CreateInputComponentInstances();

	/**
	 * 	Create a @class UVRHandInputComponent input component
	 */
	virtual UVRHandInputComponent* CreateInputComponentInstances(TSubclassOf<UVRHandInputComponent> CompClass);

	/**
	 * 	Function called by VR input component
	 */
	void SetPlayerHandStatus(EControllerHand Hand, EHandFingers Finger,float status);

private:

	UPROPERTY(Transient)
	TMap<EControllerHand, FVRHandHandInfo> PlayerHands;

	UPROPERTY(Transient)
	class APlayerController* Controller;

	UPROPERTY(Transient)
	TArray<UVRHandInputComponent*> VRInputComponent;

	// found and stored classes
	UPROPERTY(Transient, DuplicateTransient)
	TArray<TSubclassOf<UVRHandInputComponent>> VRInputComponentClasses;
	
};
