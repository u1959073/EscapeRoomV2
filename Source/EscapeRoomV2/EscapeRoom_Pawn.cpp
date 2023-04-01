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
#include "Components/SpotLightComponent.h"
#include "Components/InputComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AEscapeRoom_Pawn::AEscapeRoom_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);



	SpotFlashlight = CreateDefaultSubobject<USpotLightComponent>(TEXT("SpotFlashlight"));
    SpotFlashlight->SetupAttachment(Camera);

	FlishlightBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("FlishlightBoxComponent"));
	FlishlightBoxComponent->SetupAttachment(SpotFlashlight);


    // Set default properties for the light
    SpotFlashlight->SetIntensity(2000.0f);
    SpotFlashlight->SetLightColor(FLinearColor::White);
    SpotFlashlight->SetInnerConeAngle(20.0f);
    SpotFlashlight->SetOuterConeAngle(45.0f);
	SpotFlashlight->SetAttenuationRadius(2000.0f);

}


void AEscapeRoom_Pawn::ToggleFlashLight()
{
	//TODO: sound efects
	GEngine->AddOnScreenDebugMessage(-1, GWorld->DeltaTimeSeconds, FColor::Green, TEXT("ToggleFlashLight"));

	SpotFlashlight->ToggleVisibility();

	// if(SpotFlashlight->Intensity > 0.f)
	// {
    // 	SpotFlashlight->SetIntensity(0.f); // TODO: vigilar si afecta al rendiment, potser seria convenient crear i destruir el flaix cada cop.. ( per si el joc segueix calculant hombres i llum tot i estar la intensitat a 0)
	// }
	// else 
	// {
    // 	SpotFlashlight->SetIntensity(2000.0f); // TODO: vigilar si afecta al rendiment, potser seria convenient crear i destruir el flaix cada cop.. ( per si el joc segueix calculant hombres i llum tot i estar la intensitat a 0)
	// }

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

}

// Called to bind functionality to input
void AEscapeRoom_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


