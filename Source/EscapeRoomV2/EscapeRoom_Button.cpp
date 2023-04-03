// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeRoom_Button.h"

// Sets default values
AEscapeRoom_Button::AEscapeRoom_Button()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Scene;

	ButtonMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Button Mesh"));
	ButtonMesh->SetupAttachment(Scene);

}


void AEscapeRoom_Button::HandleInputTouch() 
{
	TArray<AActor*> Actors;
	GetOverlappingActors(
		Actors
	);

	if(Actors.Num() == 0)
	{
			GEngine->AddOnScreenDebugMessage(
				-1, 
				3.f, 
				FColor::Purple, 
				FString::Printf(TEXT("No s'ha trobat cap overlap"))
			);
	}
	else{

		for(AActor* Actor : Actors)
		{
			FString ActorName = Actor->GetActorNameOrLabel();
			GEngine->AddOnScreenDebugMessage(
				-1, 
				3.f, 
				FColor::Purple, 
				FString::Printf(TEXT("OverlapingActorName: %s"), *ActorName)
			);
	}
	}
}




// Called when the game starts or when spawned
void AEscapeRoom_Button::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEscapeRoom_Button::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TArray<AActor*> Actors;
	GetOverlappingActors(
		Actors
	);

	if(Actors.Num() == 0)
	{
			GEngine->AddOnScreenDebugMessage(
				-1, 
				GWorld->DeltaTimeSeconds, 
				FColor::Green, 
				FString::Printf(TEXT("No s'ha trobat cap overlap"))
			);
	}
	else{

		for(AActor* Actor : Actors)
		{
			FString ActorName = Actor->GetActorNameOrLabel();
			GEngine->AddOnScreenDebugMessage(
				-1, 
				GWorld->DeltaTimeSeconds, 
				FColor::Green, 
				FString::Printf(TEXT("OverlapingActorName: %s"), *ActorName)
			);
	}
	}

}

