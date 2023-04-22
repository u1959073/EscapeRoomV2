// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeRoom_LaserSensor.h"

// Sets default values
AEscapeRoom_LaserSensor::AEscapeRoom_LaserSensor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMesh;

	Sensor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sensor"));
	Sensor->SetupAttachment(StaticMesh);

}

// Called when the game starts or when spawned
void AEscapeRoom_LaserSensor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEscapeRoom_LaserSensor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEscapeRoom_LaserSensor::TurnOnOf(bool OnOff)
{
	if(OnOff)
	{
		GEngine->AddOnScreenDebugMessage(-1, GWorld->DeltaTimeSeconds, FColor::Green, FString::Printf(TEXT("Turn On")));
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, GWorld->DeltaTimeSeconds, FColor::Red, FString::Printf(TEXT("Turn Off")));
	}
	
}

