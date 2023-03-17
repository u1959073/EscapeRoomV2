// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeRoom_Balancer.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEscapeRoom_Balancer::AEscapeRoom_Balancer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Scene;

	BaseMaze = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Lab"));
	BaseMaze->SetupAttachment(Scene);

	RollingBall = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Rolling Ball"));
	RollingBall->SetupAttachment(BaseMaze);

	RollingBallSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn Point"));
	RollingBallSpawnPoint->SetupAttachment(BaseMaze);

}

// Called when the game starts or when spawned
void AEscapeRoom_Balancer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEscapeRoom_Balancer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Move();

	FRotator RootRotation = RootComponent->GetComponentRotation();
	FRotator ActorRotation = this->GetActorRotation();

	FString StringRootRotation = RootRotation.ToString();
	FString StringActorRotation = ActorRotation.ToString();


	GEngine->AddOnScreenDebugMessage(-1, GWorld->DeltaTimeSeconds, FColor::Yellow, FString::Printf(TEXT("ActorRotation: %s"), *StringActorRotation) );
	GEngine->AddOnScreenDebugMessage(-1, GWorld->DeltaTimeSeconds, FColor::Green, FString::Printf(TEXT("RootRotation: %s"), *StringRootRotation));


}


void AEscapeRoom_Balancer::Move()
{
	FRotator RootRotation = RootComponent->GetComponentRotation();

	GEngine->AddOnScreenDebugMessage(-1, GWorld->DeltaTimeSeconds, FColor::Yellow, FString::Printf(TEXT("moving")) );


	FVector DeltaLocation = FVector::ZeroVector;
	DeltaLocation.X = -RootRotation.Pitch * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);
	DeltaLocation.Y = RootRotation.Roll * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);
	RollingBall->AddLocalOffset(DeltaLocation, true);

	// AddActorLocalOffset(DeltaLocation, true);
}

