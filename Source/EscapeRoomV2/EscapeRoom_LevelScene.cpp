// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeRoom_LevelScene.h"

// Sets default values for this component's properties
UEscapeRoom_LevelScene::UEscapeRoom_LevelScene()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEscapeRoom_LevelScene::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UEscapeRoom_LevelScene::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int32 UEscapeRoom_LevelScene::GetLevel()
{
	return Level;
}

void UEscapeRoom_LevelScene::SetLevel(int32 newLevel)
{
	Level = newLevel;
}


bool UEscapeRoom_LevelScene::ManageLevel(int32 currentLevel)
{
	return false;
}


