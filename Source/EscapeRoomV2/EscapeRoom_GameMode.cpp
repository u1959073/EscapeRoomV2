// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeRoom_GameMode.h"
#include "ARBlueprintLibrary.h"
#include "ARSessionConfig.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

#include "EscapeRoom_Spawner.h"
#include "EscapeRoom_InputMotion.h"
#include "EscapeRoom_LaserEmitter.h"
#include "EscapeRoom_Level.h"

#include "ARTrackable.h"
#include "ARBlueprintLibrary.h"
#include "Containers/Array.h"
#include "Engine/Engine.h"
#include "Math/TransformNonVectorized.h"
#include "Components/InputComponent.h"
#include "ARTypes.h"


AEscapeRoom_GameMode::AEscapeRoom_GameMode()
{
    PrimaryActorTick.bStartWithTickEnabled = true;
    PrimaryActorTick.bCanEverTick = true;
	CurrentLevel = 0;

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
	GEngine->AddOnScreenDebugMessage(
		-1, 
		GWorld->DeltaTimeSeconds, 
		FColor::Red, 
		FString::Printf(TEXT("Collision component INDEX: %i"), TrackedImages.Num()));

	for (UARTrackedImage* i : TrackedImages) {
		
		if(i->GetTrackingState() == EARTrackingState::NotTracking){
			AEscapeRoom_Spawner** aux_actor = SpawnedImages.Find(i->GetDetectedImage());
			if(aux_actor != nullptr)
			{
				(*aux_actor)->GetRootComponent()->SetHiddenInGame(true, true);
			}
		}
		else {
			UARBlueprintLibrary::DebugDrawTrackedGeometry(i,this,FColor::Blue,20.f,0.f);
		
			UARCandidateImage* DetectedImage = i->GetDetectedImage();
			FTransform TrackingTransform = i->GetLocalToTrackingTransform();

			AEscapeRoom_Spawner** ActualActor = SpawnedImages.Find(DetectedImage);

			// Spawnegem un nou actor
			if(!ActualActor)
			{
				AEscapeRoom_Spawner* NewSpawnedActor = GetWorld()->SpawnActor<AEscapeRoom_Spawner>(SpawnerClass, TrackingTransform);
				if(NewSpawnedActor)
				{ 
					NewSpawnedActor->SetOwner(this);
					SpawnedImages.Add(DetectedImage, NewSpawnedActor);
					NewSpawnedActor->SetChildActor(DetectedImage); 
					NewSpawnedActor->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);
				
					ActualActor = &NewSpawnedActor;
					SetActorLevel(CurrentLevel, NewSpawnedActor->GetSpawnedActor());
				}


				// if(NewSpawnedActor && NewSpawnedActor->ChildActorHasTag("Pin"))
				// {
				// 	GEngine->AddOnScreenDebugMessage(-1, GWorld->DeltaTimeSeconds, FColor::Blue, TEXT("Pinable"));
				// 	UARBlueprintLibrary::PinComponent(NewSpawnedActor->GetRootComponent(), TrackingTransform);	
				// }
			}
			// transformem un actor ja spawnejat
			else {
				AEscapeRoom_Spawner** aux_actor = SpawnedImages.Find(i->GetDetectedImage());
				if(aux_actor != nullptr)
				{
					(*aux_actor)->GetRootComponent()->SetHiddenInGame(false, true);
				}

				if(ActualActor && !((*ActualActor)->ChildActorHasTag("Pin")))
				{
					(*ActualActor)->SetActorTransform(TrackingTransform, true);
				}			
			}
		}

		
	// code block to be executed
	}
}
//TODO: aquesta funció no ha de fer el cast a LaserEmitter sinó a Level ( que ho seran tots, però millor comprovar abans de cridar el manageLevel )

bool AEscapeRoom_GameMode::SetActorLevel(int32 Level, UChildActorComponent* actor)
{
	if(actor != nullptr )
	{
		if(AEscapeRoom_Level* actorLevel = Cast<AEscapeRoom_Level>(actor->GetChildActor()))
		{
			actorLevel->ManageLevel(Level);
			return true;
		}
	}
	return false;
}

int32 AEscapeRoom_GameMode::GetCurrentLevel()
{
	return CurrentLevel;
}

void AEscapeRoom_GameMode::ManageGameLevel(int32 Level) 
{	
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Yellow, FString::Printf(TEXT("ManageGameLevel")));

	CurrentLevel = Level;
	for (auto& Elem : SpawnedImages)
	{
		UChildActorComponent* a = Elem.Value->GetSpawnedActor();
		SetActorLevel(CurrentLevel, a);
	}
}


