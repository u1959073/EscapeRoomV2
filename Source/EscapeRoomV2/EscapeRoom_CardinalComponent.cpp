// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeRoom_CardinalComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UEscapeRoom_CardinalComponent::UEscapeRoom_CardinalComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEscapeRoom_CardinalComponent::BeginPlay()
{
	Super::BeginPlay();
	PlayerControllerRef =  UGameplayStatics::GetPlayerController(GetWorld(), 0);

	// ...
	
}


bool UEscapeRoom_CardinalComponent::IsNorth()
{
	int northAngle = GetNorthInDegrees(); 
	return northAngle > northAngleLimitDown && northAngle < northAngleLimitUp;
}

bool UEscapeRoom_CardinalComponent::IsSouth()
{
	return false;
}

bool UEscapeRoom_CardinalComponent::IsEast()
{
	return false;	
}

bool UEscapeRoom_CardinalComponent::IsWest()
{
	return false;	
}

int UEscapeRoom_CardinalComponent::GetNorth()
{
	return (int)(_tilt.Z * 100);	
}

int UEscapeRoom_CardinalComponent::GetNorthInDegrees()
{
	return GetNorth() * -180 / 313; 	
}


// Called every frame
void UEscapeRoom_CardinalComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	IsNorth();
	PlayerControllerRef->GetInputMotionState(_tilt, _rotation, _gravity, _acceleration);


	FVector _tiltAux = FVector((int)(_tilt.X + 0.5 - (_tilt.X<0)), (int)(_tilt.Y + 0.5 - (_tilt.Y<0)) , (int)(_tilt.Z + 0.5 - (_tilt.Z<0)));

	FVector _tiltAux2 = FVector((int)(_tilt.X * 100),(int)(_tilt.Y * 100), (int)(_tilt.Z * 100));

	// int _tiltX = (int)(_tilt. + 0.5 - (_tilt));

	

	GEngine->AddOnScreenDebugMessage(-1, GWorld->DeltaTimeSeconds, FColor::Red, FString::Printf(TEXT("tilt: %s"), *((_tiltAux2).ToString())));


	// ...
}

