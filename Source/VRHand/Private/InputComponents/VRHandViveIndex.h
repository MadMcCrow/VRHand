// Fill out your copyright notice in the Description page of Project Settings.


#include "VRHandInputComponent.h"
#include "VRHandViveIndex.generated.h"

/**
 *	@class	UVRHandInputComponent
 *	@brief	Input component for HTC Vive Index motion controllers
 *      @note   Does not work with OG Vive controllers nor knuckles
 */
UCLASS(Category="VRHand|Input")
class VRHAND_API UVRHandViveIndex : public UVRHandInputComponent
{
	GENERATED_BODY()

public:

	/**
	 *	Do all the Post Spawn initialisation here. 
	 */
	virtual void Init(class UVRHandSubsystem* OwningSubsystem);

	/**
	 * 	Bind all your inputs here.
	 */
	virtual void BindInputs();

};