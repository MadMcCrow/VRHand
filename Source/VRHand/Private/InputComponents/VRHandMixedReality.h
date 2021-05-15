// Fill out your copyright notice in the Description page of Project Settings.


#include "VRHandInputComponent.h"
#include "VRHandMixedReality.generated.h"

/**
 *	@class	UVRHandInputComponent
 *	@brief	Input component for Windows MR motion controllers
 */
UCLASS(Category="VRHand|Input")
class VRHAND_API UVRHandMixedReality : public UVRHandInputComponent
{
	GENERATED_BODY()

public:

	UVRHandMixedReality() : UVRHandInputComponent() 
	{}

	/**
	 *	Do all the Post Spawn initialisation here. 
	 */
	virtual void Init(class UVRHandSubsystem* OwningSubsystem);

	/**
	 * 	Bind all your inputs here.
	 */
	virtual void BindInputs();

};