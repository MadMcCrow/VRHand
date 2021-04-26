// Fill out your copyright notice in the Description page of Project Settings.


#include "VRHandSubsystem.h"
#include "Engine/LocalPlayer.h"
#include "Components/InputComponent.h"
#include "VRHandInputComponent.h"
#include "Kismet/GameplayStatics.h"

void GetAllChildClasses(TSubclassOf<UVRHandInputComponent> Base, TArray<TSubclassOf<UVRHandInputComponent>> Classes)
{
    Classes.Empty();
    for(TObjectIterator<UClass> ClassIt; ClassIt; ++ClassIt)
    {

        TSubclassOf<UVRHandInputComponent> Class =  *ClassIt;

        if (!Class)
            continue;

        // Ignore deprecated and abstract classes
        if(Class->HasAnyClassFlags(CLASS_Deprecated | CLASS_NewerVersionExists | CLASS_Abstract | CLASS_Hidden))
            continue;

#if WITH_EDITOR
        // Ignore skeleton classes (semi-compiled versions that only exist in-editor)
       	// Find generating blueprint for a class
	UBlueprint* GeneratingBP = Cast<UBlueprint>(Class->ClassGeneratedBy);
	if( GeneratingBP && GeneratingBP->SkeletonGeneratedClass )
	{
		if ((Class == GeneratingBP->SkeletonGeneratedClass) && (GeneratingBP->SkeletonGeneratedClass != GeneratingBP->GeneratedClass))
            continue;
	}
#endif // WITH_EDITOR

 // Check this class is a subclass of Base
        if(!Class->IsChildOf(Base))
        {
            continue;
        }
     
        // Add this class
        Classes.Add(Class);
    }
}


FName UVRHandSubsystem::VRInputComponentName = FName("VRInputComponent");

UVRHandSubsystem::UVRHandSubsystem() : Super()
{

}

void UVRHandSubsystem::Initialize(FSubsystemCollectionBase & Collection)
{
    Super::Initialize(Collection);

    GetAllChildClasses(UVRHandInputComponent::StaticClass(), VRInputComponentClasses );

    CreateInputComponentInstances();

    if (!Controller)
        BindControllerHandsEvents();

}

void UVRHandSubsystem::Deinitialize()
{
    Super::Deinitialize();
    VRInputComponentClasses.Empty();
    VRInputComponent.Empty();
}


void UVRHandSubsystem::BindControllerHandsEvents()
{
    ULocalPlayer* Player = GetLocalPlayer();

    if (!Player)
        return;

    // let's save player controller
    Controller = UGameplayStatics::GetPlayerControllerFromID(Player, Player->GetControllerId());

    // let's add our inputs to the PC
    for (auto inputComp :VRInputComponent )
    {
        Controller->PushInputComponent(inputComp);
    }
}



void UVRHandSubsystem::CreateInputComponentInstances()
{
    for (auto Class : VRInputComponentClasses )
    {
        if (auto inputComp = CreateInputComponentInstances(Class) )
        {
            inputComp->RegisterComponent();
            VRInputComponent.AddUnique(inputComp);
        }
    }
}

UVRHandInputComponent* UVRHandSubsystem::CreateInputComponentInstances(TSubclassOf<UVRHandInputComponent> CompClass)
{
    // TODO: Make better component name 
    FName ComponentName =  MakeUniqueObjectName( this, CompClass, FName()); 
    auto createdComp = NewObject<UVRHandInputComponent>(this, CompClass , ComponentName);
    return createdComp;
}

void UVRHandSubsystem::SetPlayerHandStatus(EControllerHand Hand, EHandFingers Finger,float status)
{
    PlayerHands[Hand][Finger] = status;
}