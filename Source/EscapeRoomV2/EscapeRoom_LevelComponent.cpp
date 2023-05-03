// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeRoom_LevelComponent.h"

// Sets default values for this component's properties
UEscapeRoom_LevelComponent::UEscapeRoom_LevelComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEscapeRoom_LevelComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UEscapeRoom_LevelComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int32 UEscapeRoom_LevelComponent::GetLevel()
{
	return Level;
}

void UEscapeRoom_LevelComponent::SetLevel(int32 newLevel)
{
	Level = newLevel;
}


bool UEscapeRoom_LevelComponent::ManageLevelComponent(int32 currentLevel)
{
	return false;
}

