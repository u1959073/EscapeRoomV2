// Fill out your copyright notice in the Description page of Project Settings.



#include "EscapeRoom_Level_2.h"
#include "EscapeRoom_Balancer.h"
#include "Components/SceneComponent.h"
#include "EscapeRoom_GameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Components/BoxComponent.h"


AEscapeRoom_Level_2::AEscapeRoom_Level_2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Level = 2;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Scene;


	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
    BaseMesh->SetupAttachment(Scene);
    BaseMesh->bDrawMeshCollisionIfSimple = true;
    BaseMesh->bDrawMeshCollisionIfComplex = true;

	CollisionBox_1 = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box 1"));
	CollisionBox_1->SetupAttachment(Scene);

	CollisionBox_2 = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box 2"));
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
    // Comprovar collisions
}

bool AEscapeRoom_Level_2::ManageLevel(int32 NewLevel)
{
	
    IsActive = Level == NewLevel;
	SetActorTickEnabled(true);
	return IsActive;
}