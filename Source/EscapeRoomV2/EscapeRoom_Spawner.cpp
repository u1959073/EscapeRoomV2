// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeRoom_Spawner.h"
#include "Components/ChildActorComponent.h"
#include "ARTypes.h"
#include "UObject/Class.h"
#include <string>

// Sets default values
AEscapeRoom_Spawner::AEscapeRoom_Spawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	ChildActor = CreateDefaultSubobject<UChildActorComponent>(TEXT("Child Actor"));
	ChildActor->SetupAttachment(RootComponent);


}

// Called when the game starts or when spawned
void AEscapeRoom_Spawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEscapeRoom_Spawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AEscapeRoom_Spawner::SetChildActor(UARCandidateImage* DetectedImage)
{
	UClass** CandidateActorClass = SpawnableImages.Find(DetectedImage);
	
	if(CandidateActorClass)
	{
		ChildActor->SetChildActorClass((*CandidateActorClass));
	}
	
}

bool AEscapeRoom_Spawner::ChildActorHasTag(FName tag) 
{
	bool res = false;
	if(ChildActor)
	{
		AActor* ChildActor_Actor = ChildActor->GetChildActor();
		if (ChildActor_Actor )
		{
			res = ChildActor_Actor->ActorHasTag("Pin");
		} 
	}


	return res;
} 



