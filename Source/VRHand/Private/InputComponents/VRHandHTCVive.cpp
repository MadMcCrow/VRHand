// Fill out your copyright notice in the Description page of Project Settings.


#include "InputComponents/VRHandHTCVive.h"


void UVRHandHTCVive::BindInputs()
{
        KeyMappings.Add(EKeys::Vive_Left_Trackpad_Touch, { EControllerHand::Left, EHandFingers::Thumb});
        KeyMappings.Add(EKeys::Vive_Left_Grip_Click,     { EControllerHand::Left, EHandFingers::Grip});

        KeyMappings.Add(EKeys::Vive_Right_Trackpad_Touch, { EControllerHand::Right, EHandFingers::Thumb});
        KeyMappings.Add(EKeys::Vive_Right_Grip_Click,     { EControllerHand::Right, EHandFingers::Grip});

        BindAxisFunction(EKeys::Vive_Left_Trigger_Axis   ,this,  &UVRHandHTCVive::OnLeftIndexAxis);
        BindAxisFunction(EKeys::Vive_Right_Trigger_Axis  ,this, &UVRHandHTCVive::OnRightIndexAxis);

        Super::BindInputs();
}

void UVRHandHTCVive::Init(class UVRHandSubsystem* OwningSubsystem)
{
        Super::Init(OwningSubsystem);
}
