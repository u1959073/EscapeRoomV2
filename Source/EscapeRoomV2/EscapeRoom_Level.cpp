// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeRoom_Level.h"

// Sets default values
AEscapeRoom_Level::AEscapeRoom_Level()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Level = 0;

}

// Called when the game starts or when spawned
void AEscapeRoom_Level::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEscapeRoom_Level::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 AEscapeRoom_Level::GetLevel()
{
	return Level;
}

void AEscapeRoom_Level::SetLevel(int32 newLevel)
{
	Level = newLevel;
}



bool AEscapeRoom_Level::ManageLevel(int32 currentLevel)
{
	return false;
}

