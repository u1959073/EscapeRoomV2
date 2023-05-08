// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeRoom_Balancer.h"
#include "Kismet/GameplayStatics.h"
#include "EscapeRoom_BalancerComponent.h"

// Sets default values
AEscapeRoom_Balancer::AEscapeRoom_Balancer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Scene;

	MovingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Moving Mesh"));
	MovingMesh->SetupAttachment(Scene);

	
	BalancerComponent = CreateDefaultSubobject<UEscapeRoom_BalancerComponent>(TEXT("Balancer Component"));
	BalancerComponent->SetMovingScene(RootComponent);

}

// Called when the game starts or when spawned
void AEscapeRoom_Balancer::BeginPlay()
{
	Super::BeginPlay();
	SetActorTickEnabled(true);
}

// Called every frame
void AEscapeRoom_Balancer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




