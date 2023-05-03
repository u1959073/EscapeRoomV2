// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeRoom_InputMotionComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Math/Quat.h"

// Sets default values for this component's properties
UEscapeRoom_InputMotionComponent::UEscapeRoom_InputMotionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

UEscapeRoom_InputMotionComponent::UEscapeRoom_InputMotionComponent(USceneComponent * SceneToMove)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Scene = SceneToMove;
	// ...
}

void UEscapeRoom_InputMotionComponent::SetMovingScene(USceneComponent* SceneToMove)
{
	Scene = SceneToMove;
}

void UEscapeRoom_InputMotionComponent::Enable()
{
	SetComponentTickEnabled(true);
}

void UEscapeRoom_InputMotionComponent::Disable()
{
	SetComponentTickEnabled(false);
}


// Called when the game starts
void UEscapeRoom_InputMotionComponent::BeginPlay()
{
	Super::BeginPlay();
	PlayerControllerRef = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	// ...
	
}


// Called every frame
void UEscapeRoom_InputMotionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	MoveMesh();
	// ...
}

void UEscapeRoom_InputMotionComponent::MoveMesh() const
{
	if(Scene != nullptr)
	{

		if(PlayerControllerRef)
		{
			FVector _tilt;
			FVector _rotation;
			FVector _gravity; 
			FVector _acceleration;

			PlayerControllerRef->GetInputMotionState(_tilt, _rotation, _gravity, _acceleration);
			GEngine->AddOnScreenDebugMessage(-1, GWorld->DeltaTimeSeconds, FColor::Red, FString::Printf(TEXT("_tilt: %s"), *(_rotation.ToString())));

			FRotator DeltaRotation = FRotator::ZeroRotator;
			// DeltaRotation.Roll = _tilt.X * 100 * UGameplayStatics::GetWorldDeltaSeconds(this);
			// DeltaRotation.Pitch = _tilt.Y * 100 * UGameplayStatics::GetWorldDeltaSeconds(this);
			DeltaRotation.Yaw = _rotation.Z * -500 * UGameplayStatics::GetWorldDeltaSeconds(this);
			Scene->AddLocalRotation(DeltaRotation, true);

		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, GWorld->DeltaTimeSeconds, FColor::Blue, FString::Printf(TEXT("No playerControllerRef")));
		}
	}
	else
	{
			GEngine->AddOnScreenDebugMessage(-1, GWorld->DeltaTimeSeconds, FColor::Blue, FString::Printf(TEXT("No Scene to move")));

	}
}

