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
	UFUNCTION(BlueprintPure, Category="VRHand|Statics")
	static UVRHandSubsystem* GetPlayerVRHandSubsystem(const class APlayerController* Player);

	/** 
	 *	Get a reference to the VR Hand subsystem
	 *	@param	Player		The player you wanna know the hands of
	 *	@return				The map off all the "hands"
	 */
	UFUNCTION(BlueprintPure, Category="VRHand|Statics")
	static TMap<EControllerHand, FVRHandHandInfo> GetPlayerVRHands(const class APlayerController* Player);

	/** 
	 *	Get a the information about the player's hands
	 *	@param	Player		The player controller from which you'll extract the Local player
	 *	@param	Hand		The hand you want info from
	 *	@return				the values for that "hand" 
	 *	@note				Only left and right hand are implemented
	 */
	UFUNCTION(BlueprintPure, Category="VRHand|Statics")
	static FVRHandHandInfo GetPlayerVRHandStatus(const class APlayerController* Player, EControllerHand Hand);


	/** 
	 *	Get the openess value about the player's hands' finger
	 *	@param	Player		The player controller from which you'll extract the Local player
	 *	@param	Hand		The hand you want info from
	 *	@param	Finger		The finger you're interested in
	 *	@return				the values for that "hand" 
	 *	@note				Only left and right hand are implemented
	 */
	UFUNCTION(BlueprintPure, Category="VRHand|Statics")
	static float GetPlayerVRHandFinger(const class APlayerController* Player, EControllerHand Hand, EHandFingers Finger);

};
