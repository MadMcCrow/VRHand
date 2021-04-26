// Fill out your copyright notice in the Description page of Project Settings.


#include "InputComponents/VRHandOculus.h"


void UVRHandOculus::BindInputs()
{
        BindAxisFunction<UVRHandOculus>(EKeys::OculusTouch_Left_Grip_Axis        , this, &UVRHandOculus::OnLeftGripAxis);
        BindAxisFunction<UVRHandOculus>(EKeys::OculusTouch_Left_Trigger_Axis     , this, &UVRHandOculus::OnLeftIndexAxis);
 	
        BindAxisFunction(EKeys::OculusTouch_Right_Grip_Axis        , this, &UVRHandOculus::OnRightGripAxis);
        BindAxisFunction(EKeys::OculusTouch_Right_Trigger_Axis     , this, &UVRHandOculus::OnRightIndexAxis);

        KeyMappings.Add(EKeys::OculusTouch_Left_Thumbstick_Touch , { EControllerHand::Left, EHandFingers::Thumb});
        KeyMappings.Add(EKeys::OculusTouch_Right_Thumbstick_Touch , { EControllerHand::Left, EHandFingers::Thumb});

        Super::BindInputs();
}

void UVRHandOculus::Init(class UVRHandSubsystem* OwningSubsystem)
{
        Super::Init(OwningSubsystem);
}
