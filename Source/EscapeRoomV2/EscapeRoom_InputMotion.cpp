// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeRoom_InputMotion.h"
#include "Kismet/GameplayStatics.h"

#include "Math/Quat.h"

// Sets default values
AEscapeRoom_InputMotion::AEscapeRoom_InputMotion()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Scene;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(Scene);

}

// Called when the game starts or when spawned
void AEscapeRoom_InputMotion::BeginPlay()
{
	Super::BeginPlay();


	PlayerControllerRef =  UGameplayStatics::GetPlayerController(GetWorld(), 0);


	
}

// Called every frame
void AEscapeRoom_InputMotion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// TODO: intentar que el MoveMesh només es faci quan està visible l'actor InputMotin!
	MoveMesh();

}

void AEscapeRoom_InputMotion::MoveMesh() const
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

		BaseMesh->AddLocalRotation(DeltaRotation, true);

	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, GWorld->DeltaTimeSeconds, FColor::Blue, FString::Printf(TEXT("No playerControllerRef")));
	}
}




