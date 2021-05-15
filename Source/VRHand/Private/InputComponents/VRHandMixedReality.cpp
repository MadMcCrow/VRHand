// Fill out your copyright notice in the Description page of Project Settings.


#include "InputComponents/VRHandMixedReality.h"


void UVRHandMixedReality::BindInputs()
{
        KeyMappings.Add(EKeys::MixedReality_Left_Trackpad_Touch, { EControllerHand::Left, EHandFingers::Thumb});
        KeyMappings.Add(EKeys::MixedReality_Left_Grip_Click,     { EControllerHand::Left, EHandFingers::Grip});

        KeyMappings.Add(EKeys::MixedReality_Right_Trackpad_Touch, { EControllerHand::Right, EHandFingers::Thumb});
        KeyMappings.Add(EKeys::MixedReality_Right_Grip_Click,     { EControllerHand::Right, EHandFingers::Grip});

        BindAxisFunction(EKeys::MixedReality_Left_Trigger_Axis   , this, &UVRHandMixedReality::OnLeftIndexAxis);
        BindAxisFunction(EKeys::MixedReality_Right_Trigger_Axis   , this, &UVRHandMixedReality::OnRightIndexAxis);   	
        Super::BindInputs();
}

void UVRHandMixedReality::Init(class UVRHandSubsystem* OwningSubsystem)
{
        Super::Init(OwningSubsystem);
}
