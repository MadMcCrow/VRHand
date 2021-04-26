// Fill out your copyright notice in the Description page of Project Settings.


#include "VRHandFunctionLibrary.h"
#include "Engine/LocalPlayer.h"


UVRHandSubsystem* UVRHandFunctionLibrary::GetPlayerVRHandSubsystem(const class APlayerController* Player)
{
    if (Player)
    {
        if ( auto LP = Cast<ULocalPlayer>(Player->Player))
        {
            return LP->GetSubsystem<UVRHandSubsystem>();
        }
    }
    return nullptr;
}

TMap<EControllerHand, FVRHandHandInfo> UVRHandFunctionLibrary::GetPlayerVRHands(const class APlayerController* Player)
{
    if (auto VRSS = GetPlayerVRHandSubsystem(Player))
    {
        return VRSS->GetHands();
    }
    return TMap<EControllerHand, FVRHandHandInfo>();
}

FVRHandHandInfo UVRHandFunctionLibrary::GetPlayerVRHandStatus(const class APlayerController* Player, EControllerHand Hand)
{
    if (auto VRSS = GetPlayerVRHandSubsystem(Player))
    {
        return VRSS->GetHandStatus(Hand);
    }
    return FVRHandHandInfo();
}

float UVRHandFunctionLibrary::GetPlayerVRHandFinger(const class APlayerController* Player, EControllerHand Hand, EHandFingers Finger)
{
    if (auto VRSS = GetPlayerVRHandSubsystem(Player))
    {
        return VRSS->GetHandStatus(Hand)[Finger];
    }
    return 0.f;
}