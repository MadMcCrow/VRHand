// Fill out your copyright notice in the Description page of Project Settings.


#include "InputComponents/VRHandViveIndex.h"


void UVRHandViveIndex::BindInputs()
{
        BindAxisFunction(EKeys::ValveIndex_Left_Grip_Axis        ,this, &UVRHandViveIndex::OnLeftGripAxis);
        BindAxisFunction(EKeys::ValveIndex_Left_Trigger_Axis     ,this, &UVRHandViveIndex::OnLeftIndexAxis);
	
        BindAxisFunction(EKeys::ValveIndex_Right_Grip_Axis        ,this, &UVRHandViveIndex::OnRightGripAxis);
        BindAxisFunction(EKeys::ValveIndex_Right_Trigger_Axis     ,this, &UVRHandViveIndex::OnRightIndexAxis);

        KeyMappings.Add(EKeys::ValveIndex_Right_Trackpad_Touch, { EControllerHand::Left, EHandFingers::Thumb});
        KeyMappings.Add(EKeys::ValveIndex_Left_Trackpad_Touch , { EControllerHand::Right, EHandFingers::Thumb});

        Super::BindInputs();
}

void UVRHandViveIndex::Init(class UVRHandSubsystem* OwningSubsystem)
{
        Super::Init(OwningSubsystem);
}
