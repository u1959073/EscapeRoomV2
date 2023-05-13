// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeRoom_Level_1.h"
#include "Blueprint/UserWidget.h"
#include "HintWidget.h"
#include "Layout/Visibility.h"
#include "Components/SlateWrapperTypes.h"

AEscapeRoom_Level_1::AEscapeRoom_Level_1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Level = 1;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Scene;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(Scene);


	SpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn Point"));
	SpawnPoint->SetupAttachment(RootComponent);


	// LevelCompletedHintSpawnPoint_1 = CreateDefaultSubobject<USceneComponent>(TEXT("Level 1 Completed Hint Spawn Point"));
	// LevelCompletedHintSpawnPoint_1->SetupAttachment(Scene);
	// LevelCompletedHintSpawnPoint = LevelCompletedHintSpawnPoint_1;


}

void AEscapeRoom_Level_1::BeginPlay()
{
	Super::BeginPlay();
	// SetActorTickEnabled(false);
	
	SetActorTickEnabled(true);

	// FTransform SocketTransform = BaseMesh->GetSocketTransform(TEXT("UVTextSocket"));
	// UVTextCode = GetWorld()->SpawnActor<AActor>(UVTextCodeClass, SocketTransform);
	// if(UVTextCode != nullptr)
	// {
	// 	UVTextCode->AttachToComponent( BaseMesh , FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("UVTextSocket"));
	// 	UVTextCode->SetOwner(this);
	// }

	// SocketTransform = BaseMesh->GetSocketTransform(TEXT("UVLightSocket"));
	// UVLight = GetWorld()->SpawnActor<AActor>(UVLightClass, SocketTransform);
	// if(UVLight != nullptr)
	// {
	// 	UVLight->AttachToComponent( BaseMesh , FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("UVLightSocket"));
	// 	UVLight->SetOwner(this);
	// }



}

void AEscapeRoom_Level_1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}


bool AEscapeRoom_Level_1::ManageLevel(int32 NewLevel)
{
	// Super::ManageLevel(NewLevel);
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, FString::Printf(TEXT("Manage Level 1")));
	if(NewLevel > Level)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, FString::Printf(TEXT("IN IF")));
		SpawnCompletedLevelHint();
	}
	IsActive = Level == NewLevel;
	SetWarningLight(Level < NewLevel);
	SetActorTickEnabled(true);
	SetHints(NewLevel);
	return IsActive;
}

// void AEscapeRoom_Level_1::ShowHint_Implementation()
// {
// 	GEngine->AddOnScreenDebugMessage(-1, GWorld->DeltaTimeSeconds, FColor::Yellow, FString::Printf(TEXT("SHOWING LEVEL 2 HINT")) );
// 	if(IsValid(HintWidgetClass))
// 	{
// 		if(HintWidget == nullptr)
// 		{
// 			HintWidget = Cast<UHintWidget>(CreateWidget(GetWorld(), HintWidgetClass));
// 			if(HintWidget != nullptr)
// 			{
// 				HintWidget->AddToViewport();
// 				HintWidget->PrintText(Hints[HintIndex]);
// 				HintIndex++;
// 				if(HintIndex >= Hints.Num())
// 				{
// 					HintIndex = 0;
// 				}
// 			}
// 		}
// 		else{
// 			HintWidget->SetVisibility(ESlateVisibility::Visible);
// 			HintWidget->PrintText(Hints[HintIndex]);
// 			if(HintIndex >= Hints.Num())
// 			{
// 				HintIndex = 0;
// 			}
// 		}
// 	}

// }

void AEscapeRoom_Level_1::SetHints(int32 newLevel)
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