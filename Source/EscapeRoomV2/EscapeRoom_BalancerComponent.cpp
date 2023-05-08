// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeRoom_BalancerComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"

// Sets default values for this component's properties
UEscapeRoom_BalancerComponent::UEscapeRoom_BalancerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEscapeRoom_BalancerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UEscapeRoom_BalancerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	Move();
	// ...
}

void UEscapeRoom_BalancerComponent::SetMovingScene(USceneComponent* SceneToMove)
{
	Scene = SceneToMove;
}


void UEscapeRoom_BalancerComponent::Enable()
{
	SetComponentTickEnabled(true);
}

void UEscapeRoom_BalancerComponent::Disable()
{
	SetComponentTickEnabled(false);
}

void UEscapeRoom_BalancerComponent::Move()
{
	AActor* owner = GetOwner();
	if( owner != nullptr)
	{
		FRotator RootRotation = owner->GetRootComponent()->GetComponentRotation();

		GEngine->AddOnScreenDebugMessage(-1, GWorld->DeltaTimeSeconds, FColor::Yellow, FString::Printf(TEXT("moving")) );


		FVector DeltaLocation = FVector::ZeroVector;
		DeltaLocation.X = -RootRotation.Pitch * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);
		DeltaLocation.Y = RootRotation.Roll * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);
		FHitResult* HitResult = nullptr;
		Scene->AddLocalOffset(DeltaLocation, true, HitResult);
		if(HitResult != nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, GWorld->DeltaTimeSeconds, FColor::Yellow, FString::Printf(TEXT("Collision")) );
		} 
		else 
		{
			GEngine->AddOnScreenDebugMessage(-1, GWorld->DeltaTimeSeconds, FColor::Yellow, FString::Printf(TEXT("NO Collision")) );
		}
	}

	// AddActorLocalOffset(DeltaLocation, true);
}
