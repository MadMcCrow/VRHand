// Fill out your copyright notice in the Description page of Project Settings.


#include "VRHandInputComponent.h"


void UVRHandInputComponent::BindInputs()
{
        // automatically bind all action in KeyMapping
        for (auto InputPair : KeyMappings)
        {
                BindKeyFunction(InputPair.Key, this, &UVRHandInputComponent::OnActionKeyInput);
        }
        // now the subclass do the rest
}

void UVRHandInputComponent::Init(class UVRHandSubsystem* OwningSubsystem)
{
        Subsystem = OwningSubsystem;
}

float UVRHandInputComponent::GetInputAnalogKeyState( const FKey Key ) const
{
	if (auto VRSS = GetVRHandSubsystem())
	{	
		if (auto PC = VRSS->GetController())
		{
			return PC->GetInputAnalogKeyState(Key );
		}
	}
        return 0.f;
}

void UVRHandInputComponent::OnLeftThumbAxis(float value)
{
        if (GetVRHandSubsystem())
        {
                GetVRHandSubsystem()->SetPlayerHandStatus(EControllerHand::Left, EHandFingers::Thumb, value);
        }
}

void UVRHandInputComponent::OnLeftIndexAxis(float value)
{
        if (GetVRHandSubsystem())
        {
                GetVRHandSubsystem()->SetPlayerHandStatus(EControllerHand::Left, EHandFingers::Index, value);
        }
}

void UVRHandInputComponent::OnLeftMiddleAxis(float value)
{
        if (GetVRHandSubsystem())
        {
                GetVRHandSubsystem()->SetPlayerHandStatus(EControllerHand::Left, EHandFingers::Middle, value);
        }
}

void UVRHandInputComponent::OnLeftRingAxis(float value)
{
        if (GetVRHandSubsystem())
        {
                GetVRHandSubsystem()->SetPlayerHandStatus(EControllerHand::Left, EHandFingers::Ring, value);
        }
}

void UVRHandInputComponent::OnLeftPinkyAxis(float value)
{
        if (GetVRHandSubsystem())
        {
                GetVRHandSubsystem()->SetPlayerHandStatus(EControllerHand::Left, EHandFingers::Pinky, value);
        }
}

void UVRHandInputComponent::OnLeftGripAxis(float value)
{
        if (GetVRHandSubsystem())
        {
                GetVRHandSubsystem()->SetPlayerHandStatus(EControllerHand::Left, EHandFingers::Grip, value);
        }
}

void UVRHandInputComponent::OnRightThumbAxis(float value)
{
        if (GetVRHandSubsystem())
        {
                GetVRHandSubsystem()->SetPlayerHandStatus(EControllerHand::Right, EHandFingers::Thumb, value);
        }
}

void UVRHandInputComponent::OnRightIndexAxis(float value)
{
        if (GetVRHandSubsystem())
        {
                GetVRHandSubsystem()->SetPlayerHandStatus(EControllerHand::Right, EHandFingers::Index, value);
        }
}

void UVRHandInputComponent::OnRightMiddleAxis(float value)
{
        if (GetVRHandSubsystem())
        {
                GetVRHandSubsystem()->SetPlayerHandStatus(EControllerHand::Right, EHandFingers::Middle, value);
        }
}

void UVRHandInputComponent::OnRightRingAxis(float value)
{
        if (GetVRHandSubsystem())
        {
                GetVRHandSubsystem()->SetPlayerHandStatus(EControllerHand::Right, EHandFingers::Ring, value);
        }
}

void UVRHandInputComponent::OnRightPinkyAxis(float value)
{
        if (GetVRHandSubsystem())
        {
                GetVRHandSubsystem()->SetPlayerHandStatus(EControllerHand::Right, EHandFingers::Pinky, value);
        }
}

void UVRHandInputComponent::OnRightGripAxis(float value)
{
        if (GetVRHandSubsystem())
        {
                GetVRHandSubsystem()->SetPlayerHandStatus(EControllerHand::Right, EHandFingers::Grip, value);
        }
}


void UVRHandInputComponent::OnActionKeyInput(FKey InKey)
{
        const float value = GetInputAnalogKeyState(InKey);
        const FVRHandKeyMapping *Mapping = KeyMappings.Find(InKey);
        if (Mapping != nullptr && GetVRHandSubsystem())
        {
                GetVRHandSubsystem()->SetPlayerHandStatus(Mapping->Hand, Mapping->Finger, value);
        }
}