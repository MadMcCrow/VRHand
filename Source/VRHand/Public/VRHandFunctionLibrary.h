// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VRHandSubsystem.h"
#include "VRHandFunctionLibrary.generated.h"




/**
 * 	Collection of blueprint Exposed functions
 */
UCLASS(Category="VRHand")
class VRHAND_API UVRHandFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 
	 *	Get a reference to the VR Hand subsystem
	 *	@param	Player		The player controller from which you'll extract the Local player
	 *	@return				the subsystem
	 */
	UFUNCTION(BlueprintCallable, Category="VRHand|Statics")
	static UVRHandSubsystem* GetPlayerVRHandSubsystem(const class APlayerController* Player);

	/** 
	 *	Get a reference to the VR Hand subsystem
	 *	@param	Player		The player you wanna know the hands of
	 *	@return				The map off all the "hands"
	 */
	UFUNCTION(BlueprintCallable, Category="VRHand|Statics")
	static TMap<EControllerHand, FVRHandHandInfo> GetPlayerVRHands(const class APlayerController* Player);

	/** 
	 *	Get a reference to the VR Hand subsystem
	 *	@param	Player		The player controller from which you'll extract the Local player
	 *	@return				the values for that "hand" 
	 *	@note				Only left and right hand are implemented
	 */
	UFUNCTION(BlueprintCallable, Category="VRHand|Statics")
	static FVRHandHandInfo GetPlayerVRHandStatus(const class APlayerController* Player, EControllerHand Hand);


};
