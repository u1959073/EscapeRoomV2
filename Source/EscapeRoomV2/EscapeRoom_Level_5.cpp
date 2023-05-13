// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeRoom_Level_5.h"
#include "Components/SlateWrapperTypes.h"

AEscapeRoom_Level_5::AEscapeRoom_Level_5()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Level = 5;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Scene;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(Scene);
    BaseMesh->SetVisibility(ESlateVisibility::Hidden);

}

void AEscapeRoom_Level_5::BeginPlay()
{
	Super::BeginPlay();
	SetActorTickEnabled(true);

}

void AEscapeRoom_Level_1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

bool AEscapeRoom_Level_5::ManageLevel(int32 NewLevel)
{
	// Super::ManageLevel(NewLevel);
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, FString::Printf(TEXT("Manage Level 5")));
	if(NewLevel > Level)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, FString::Printf(TEXT("WON GAME!")));
	}
	IsActive = Level == NewLevel;
	// SetWarningLight(Level < NewLevel);
	SetActorTickEnabled(true);
    BaseMesh->SetVisibility(IsActive);
	SetHints(NewLevel);
	return IsActive;
}

void AEscapeRoom_Level_5::SetHints(int32 newLevel)
{
	Hints.Empty();
	HintIndex = 0;
	if(newLevel < Level)
	{
		Hints.Emplace(TEXT("You are not ready yet."));
	}
	else if(newLevel == Level)
	{
		Hints.Emplace(TEXT("What's hidden can't be seen by sight,\nUse this light to make it bright."));
		Hints.Emplace(TEXT("Invisible ink lies on this page,\nShine a UV light to reveal the sage."));
	}
	else if(newLevel > Level)
	{
		Hints.Emplace(TEXT("This level has already been solved."));
	}
}