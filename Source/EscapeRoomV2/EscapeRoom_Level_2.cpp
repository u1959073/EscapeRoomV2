// Fill out your copyright notice in the Description page of Project Settings.



#include "EscapeRoom_Level_2.h"
#include "EscapeRoom_Balancer.h"
#include "Components/SceneComponent.h"
#include "EscapeRoom_GameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "HintWidget.h"
#include "Layout/Visibility.h"
#include "Components/SlateWrapperTypes.h"

// #include "Components/BoxComponent.h"
#include "EscapeRoom_Trigger.h"


AEscapeRoom_Level_2::AEscapeRoom_Level_2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Level = 2;
	HintIndex = 0;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Scene;


	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
    BaseMesh->SetupAttachment(Scene);
    BaseMesh->bDrawMeshCollisionIfSimple = true;
    BaseMesh->bDrawMeshCollisionIfComplex = true;

	CollisionBox_1 = CreateDefaultSubobject<UEscapeRoom_Trigger>(TEXT("Collision Box 1"));
	CollisionBox_1->SetupAttachment(Scene);

	CollisionBox_2 = CreateDefaultSubobject<UEscapeRoom_Trigger>(TEXT("Collision Box 2"));
	CollisionBox_2->SetupAttachment(Scene);

	

}

void AEscapeRoom_Level_2::BeginPlay()
{
	Super::BeginPlay();
	SetActorTickEnabled(true);

	FTransform SocketTransform = BaseMesh->GetSocketTransform(TEXT("BalancerSocket_1"));
	Balancer_1 = GetWorld()->SpawnActor<AEscapeRoom_Balancer>(BalancerClass, SocketTransform);
	
	if(Balancer_1 != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Yellow, FString::Printf(TEXT("Balancer Spawned")));
		Balancer_1->AttachToComponent( BaseMesh , FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("BalancerSocket_1"));
		Balancer_1->SetOwner(this);
		Balancer_1->SetLevel(Level);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Yellow, FString::Printf(TEXT("Balancer NOT Spawned")));

	}

	SocketTransform = BaseMesh->GetSocketTransform(TEXT("BalancerSocket_2"));
	Balancer_2 = GetWorld()->SpawnActor<AEscapeRoom_Balancer>(BalancerClass, SocketTransform);
	
	if(Balancer_2 != nullptr)
	{
		Balancer_2->AttachToComponent( BaseMesh , FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("BalancerSocket_2"));
		Balancer_2->SetOwner(this);
		Balancer_2->SetLevel(Level);
	}

	
	// if(Mirror_1 != nullptr)
	// {
	// 	MirrorInputMotionComp->SetMovingScene(Mirror_1);
	// }


}


void AEscapeRoom_Level_2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(CollisionBox_1->IsPressed() && CollisionBox_2->IsPressed())
	{
		GEngine->AddOnScreenDebugMessage(-1, GWorld->DeltaTimeSeconds, FColor::Yellow, FString::Printf(TEXT("Next Level!")) );
		AEscapeRoom_GameMode *GameMode = Cast<AEscapeRoom_GameMode>(UGameplayStatics::GetGameMode(this));
		if(GameMode != nullptr)
		{
			GameMode->ManageGameLevel(3);
		}

	}	
    // Comprovar collisions
}

bool AEscapeRoom_Level_2::ManageLevel(int32 NewLevel)
{
	
    IsActive = Level == NewLevel;
	SetActorTickEnabled(IsActive);
	SetHints(NewLevel);
	HintIndex = 0;
	if(Balancer_1 != nullptr)
	{
		Balancer_1->ManageLevel(NewLevel);
	}
	if(Balancer_2 != nullptr)
	{
		Balancer_2->ManageLevel(NewLevel);
	}
	return IsActive;
}

// void AEscapeRoom_Level_2::ShowHint_Implementation()
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
// 		}
// 	}

// }

void AEscapeRoom_Level_2::SetHints(int32 newLevel)
{
	Hints.Empty();
	HintIndex = 0;
	if(newLevel < Level)
	{
		Hints.Emplace(TEXT("Crack the code before you proceed,\nTo unlock the path you need."));
	}
	else if(newLevel == Level)
	{
		Hints.Emplace(TEXT("Move with grace, tilt with might,\nActivate the buttons to shed some light."));
		Hints.Emplace(TEXT("Use the force of motion to make a switch,\nTilt your world and make them twitch."));
	}
	else if(newLevel > Level)
	{
		Hints.Emplace(TEXT("This level has already been solved."));
	}
}
