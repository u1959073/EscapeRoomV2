// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeRoom_Trigger.h"

UEscapeRoom_Trigger::UEscapeRoom_Trigger()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UEscapeRoom_Trigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


    AActor* CollisionActor = GetAcceptableActor();
    if (CollisionActor != nullptr)
    {
        Pressed = true;
    }
    else
    {
        Pressed = false;
    }
}

AActor* UEscapeRoom_Trigger::GetAcceptableActor() const
{
    TArray<AActor*> Actors;
    GetOverlappingActors(Actors);
    for (AActor* Actor : Actors)
    {
        bool HasAcceptableTag = Actor->ActorHasTag(AcceptableActorTag);
        if (HasAcceptableTag)
        {
            return Actor;
        }
    }

    return nullptr;
}

bool UEscapeRoom_Trigger::IsPressed() const
{
    return Pressed;
}
