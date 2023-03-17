// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeRoom_Pawn.h"
#include "EscapeRoom_Spawner.h"
#include "EscapeRoom_InputMotion.h"

#include "Camera/CameraComponent.h"
#include "ARTrackable.h"
#include "ARBlueprintLibrary.h"
#include "Containers/Array.h"
#include "Engine/Engine.h"
#include "Math/TransformNonVectorized.h"

 	

#include "Components/InputComponent.h"

// Sets default values
AEscapeRoom_Pawn::AEscapeRoom_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AEscapeRoom_Pawn::BeginPlay()
{
	Super::BeginPlay();
	PlayerControllerRef = Cast<APlayerController>(GetController());
	
}

// Called every frame
void AEscapeRoom_Pawn::Tick(float DeltaTime)
{	

	Super::Tick(DeltaTime);

	GEngine->AddOnScreenDebugMessage(-1, GWorld->DeltaTimeSeconds, FColor::Green, TEXT("This is parent"));
	
	TArray<UARTrackedImage*> TrackedImages = UARBlueprintLibrary::GetAllGeometriesByClass<UARTrackedImage>();

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

// Called to bind functionality to input
void AEscapeRoom_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


}


