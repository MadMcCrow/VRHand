// Fill out your copyright notice in the Description page of Project Settings.


#include "VRHandInputComponent.h"
#include "VRHandOculus.generated.h"

/**
 *	@class	UVRHandInputComponent
 *	@brief	Input component for Oculus Touch motion controllers
 */
UCLASS(Category="VRHand|Input")
class VRHAND_API UVRHandOculus : public UVRHandInputComponent
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