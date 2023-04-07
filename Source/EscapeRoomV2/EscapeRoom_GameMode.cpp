// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeRoom_GameMode.h"
#include "ARBlueprintLibrary.h"
#include "ARSessionConfig.h"
#include "Kismet/KismetSystemLibrary.h"

#include "EscapeRoom_Spawner.h"
#include "EscapeRoom_InputMotion.h"

#include "ARTrackable.h"
#include "ARBlueprintLibrary.h"
#include "Containers/Array.h"
#include "Engine/Engine.h"
#include "Math/TransformNonVectorized.h"
#include "Components/InputComponent.h"


AEscapeRoom_GameMode::AEscapeRoom_GameMode()
{
    PrimaryActorTick.bStartWithTickEnabled = true;
    PrimaryActorTick.bCanEverTick = true;
}


void AEscapeRoom_GameMode::BeginPlay()
{
    Super::BeginPlay();
    UARBlueprintLibrary::StartARSession(EscapeRoom_SessionConfig);
    UKismetSystemLibrary::ControlScreensaver(false);

}

// Called every frame
void AEscapeRoom_GameMode::Tick(float DeltaTime) 
{	

	Super::Tick(DeltaTime);

	GEngine->AddOnScreenDebugMessage(-1, GWorld->DeltaTimeSeconds, FColor::Green, TEXT("This is parent"));
	
	TArray<UARTrackedImage*> TrackedImages = UARBlueprintLibrary::GetAllGeometriesByClass<UARTrackedImage>();

	// for (UARTrackedImage* i: AuxTrackedImages )
	// {
	// 	if(!TrackedImages.Contains(i))
	// 	{
	// 		int position = AuxTrackedImages.Find(i);
	// 		UARTrackedImage* image = AuxTrackedImages[position];
			
	// 		// AEscapeRoom_Spawner**  = SpawnedImages.Find(DetectedImage);

	// 		AEscapeRoom_Spawner** aux_actor = SpawnedImages.Find(image->GetDetectedImage());

	// 		(*aux_actor)->SetSpawnActorVisibility(image->GetDetectedImage(),false);

	// 	}
	// }

	for (UARTrackedImage* i : TrackedImages) {

		UARCandidateImage* DetectedImage = i->GetDetectedImage();
		FTransform TrackingTransform = i->GetLocalToTrackingTransform();

		AEscapeRoom_Spawner** ActualActor = SpawnedImages.Find(DetectedImage);

		if(!ActualActor)
		{
			AEscapeRoom_Spawner* NewSpawnedActor = GetWorld()->SpawnActor<AEscapeRoom_Spawner>(SpawnerClass, TrackingTransform);
			NewSpawnedActor->SetOwner(this);
			SpawnedImages.Add(DetectedImage, NewSpawnedActor);
			NewSpawnedActor->SetChildActor(DetectedImage); 
			NewSpawnedActor->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);
			ActualActor = &NewSpawnedActor;

			if(NewSpawnedActor && NewSpawnedActor->ChildActorHasTag("Pin"))
			{
				GEngine->AddOnScreenDebugMessage(-1, GWorld->DeltaTimeSeconds, FColor::Blue, TEXT("Pinable"));
				UARBlueprintLibrary::PinComponent(NewSpawnedActor->GetRootComponent(), TrackingTransform);	
			}
		}
		else {
			if(ActualActor && !((*ActualActor)->ChildActorHasTag("Pin")))
			{
				(*ActualActor)->SetActorTransform(TrackingTransform, true);
			}			
		}

		UARBlueprintLibrary::DebugDrawTrackedGeometry(
			i,
			this,
			FColor::Blue,
			20.f,
			0.f
		);
	// code block to be executed
	}
	

}


