// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputCoreTypes.h"
#include "VRHandStructs.generated.h"


/**
 *	@enum	FVRHandHandInfo
 *	@brief	all fingers of the hand with iteration helpers
 */
UENUM(BlueprintType, Category="VRHand")
enum class EHandFingers : uint8
{
	None 	= 0	UMETA(Hidden),
	Thumb	= 0 UMETA(DisplayName="Thumb"),
	Index 	= 1 UMETA(DisplayName="Index"),
	Middle	= 2 UMETA(DisplayName="Middle"),
	Ring 	= 3	UMETA(DisplayName="Ring"),
	Pinky 	= 4	UMETA(DisplayName="Pinky"),
	Grip    = 5 UMETA(DisplayName="Grip"),
	Max 	= 5	UMETA(Hidden)
};


/**
 *	@struct FVRHandKeyMapping
 *	@brief	Simple struct to for key mapping, allowing to define a Hand + finger combinaison
 */
USTRUCT(BlueprintType, Category="VRHand")
struct VRHAND_API FVRHandKeyMapping
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY()
	EControllerHand Hand;

	UPROPERTY()
	EHandFingers Finger;

	FVRHandKeyMapping(EControllerHand InHand = EControllerHand::Left, EHandFingers InFinger = EHandFingers::None) : Hand(InHand), Finger(InFinger)
	{}
};


/**
 *	@struct FVRHandHandInfo
 *	@brief	Simple struct to describe the status of your hand, no matter the controller used
 */
USTRUCT(BlueprintType, Category="VRHand")
struct VRHAND_API FVRHandHandInfo
{
	GENERATED_USTRUCT_BODY()

public:

	FVRHandHandInfo() 
	{
	}


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<EHandFingers,float> FingersCloseStatus;

	/**
	 * 	Simple Getter that does the Fingers = grip conversion for you
	 */
	FORCEINLINE float GetStatus(EHandFingers Finger) const
	{
		switch (Finger)
		{
		
		case EHandFingers::Thumb	:
		case EHandFingers::Index	:
		{
			if (const float* value = FingersCloseStatus.Find(Finger))
				return *value;
		}
		break;
		case EHandFingers::Middle	:
		case EHandFingers::Ring	 	:
		case EHandFingers::Pinky	:
		{
			if (const float* value = FingersCloseStatus.Find(Finger))
				return *value;
		}
		// fall through because we default to Grip
		// [[fallthrough]]
		case EHandFingers::Grip	   	:
		{
			if (const float* value = FingersCloseStatus.Find(EHandFingers::Grip))
				return *value;
		}
		break;
		default:
		break;
		}
		return 0.f;
	}

	FORCEINLINE       float& operator[](EHandFingers Key) { 	  return FingersCloseStatus.FindChecked(Key); }
	FORCEINLINE const float& operator[](EHandFingers Key) const { return FingersCloseStatus.FindChecked(Key); }

};