// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/InputComponent.h"
#include "VRHandStructs.h"
#include "VRHandInputComponent.generated.h"


/**
 *	@class	UVRHandInputComponent
 *	@brief	Input component for VR motion controllers
 */
UCLASS(Category="VRHand", Abstract)
class VRHAND_API UVRHandInputComponent : public UInputComponent
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


	UFUNCTION(BlueprintPure)
	class UVRHandSubsystem* GetVRHandSubsystem() const {return Subsystem;}

	UFUNCTION(BlueprintPure)
	float GetInputAnalogKeyState( const FKey Key ) const;


protected:

	UPROPERTY(Transient)
	TMap<FKey, FVRHandKeyMapping> KeyMappings;

protected:

template<class UserClass>
	using AxisFunc = typename FInputAxisHandlerSignature::TUObjectMethodDelegate< UserClass >::FMethodPtr ;

	template<class UserClass>
	using InputFunc = typename FInputActionHandlerSignature::TUObjectMethodDelegate< UserClass >::FMethodPtr ;

	template<class UserClass>
	using KeyFunc = typename FInputActionHandlerWithKeySignature::TUObjectMethodDelegate< UserClass >::FMethodPtr ;
	
	template<class UserClass>
	FInputKeyBinding& BindKey( const FKey Key, const EInputEvent KeyEvent, UserClass* Object, KeyFunc<UserClass> Func )
	{
		auto Chord = FInputChord(Key, false, false, false, false);
		FInputKeyBinding KB(Chord, KeyEvent);
		KB.KeyDelegate.BindDelegate(Object, Func);
		KeyBindings.Emplace(MoveTemp(KB));
		return KeyBindings.Last();
	}


	template<class T>
	void BindAxisFunction(FKey InKey, T* Obj, AxisFunc<T> Func)
	{
        FInputAxisKeyBinding& binding = BindAxisKey(InKey ,Obj,Func);
        binding.bConsumeInput = false;
        binding.bExecuteWhenPaused = true;
	}

	template<class T>
	void BindKeyFunction(FKey InKey, T* Obj,  KeyFunc<T> Func)
	{
		{
			FInputKeyBinding& binding = BindKey(InKey ,EInputEvent::IE_Pressed, Obj ,Func);
			binding.bConsumeInput = false;
        	binding.bExecuteWhenPaused = true;
		}
		{
			FInputKeyBinding& binding = BindKey(InKey ,EInputEvent::IE_Pressed, Obj ,Func);
			binding.bConsumeInput = false;
        	binding.bExecuteWhenPaused = true;
		}
	}


protected:

	/* Input binding functions */
	UFUNCTION()	void OnLeftThumbAxis(float value);
	UFUNCTION()	void OnLeftIndexAxis(float value);
	UFUNCTION()	void OnLeftMiddleAxis(float value);
	UFUNCTION()	void OnLeftRingAxis(float value);
	UFUNCTION()	void OnLeftPinkyAxis(float value);
	UFUNCTION()	void OnLeftGripAxis(float value);

	UFUNCTION() void OnRightThumbAxis(float value);
	UFUNCTION() void OnRightIndexAxis(float value);
	UFUNCTION() void OnRightMiddleAxis(float value);
	UFUNCTION() void OnRightRingAxis(float value);
	UFUNCTION() void OnRightPinkyAxis(float value);
	UFUNCTION() void OnRightGripAxis(float value);

	UFUNCTION() void OnActionKeyInput(FKey InKey);
	/* \Input binding functions */

private:
	UPROPERTY(Transient)
	class UVRHandSubsystem* Subsystem;
};
