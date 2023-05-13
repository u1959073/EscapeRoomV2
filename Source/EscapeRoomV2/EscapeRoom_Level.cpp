// Fill out your copyright notice in the Description page of Project Settings.




#include "EscapeRoom_Level.h"
#include "Components/SpotLightComponent.h"
#include "Components/SlateWrapperTypes.h"
#include "Blueprint/UserWidget.h"
#include "HintWidget.h"



// Sets default values
AEscapeRoom_Level::AEscapeRoom_Level()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Level = 0;

	SpotLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("SpotLight"));
    SpotLight->SetupAttachment(RootComponent);

	// LevelCompletedHintSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Level Completed Hint Spawn Point"));
	// LevelCompletedHintSpawnPoint->SetupAttachment(RootComponent);

	SpotLight->SetIntensity(10000.0f);
    SpotLight->SetVisibility(true);

	SpotLight->SetLightColor(FLinearColor::White);
    SpotLight->SetInnerConeAngle(20.0f);
    SpotLight->SetOuterConeAngle(45.0f);
	SpotLight->SetAttenuationRadius(500.0f);
	FRotator LightRotation = FRotator(-90.f, 0.f, 0.f); 
	SpotLight->AddWorldRotation(LightRotation);

	



}

// Called when the game starts or when spawned
void AEscapeRoom_Level::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEscapeRoom_Level::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 AEscapeRoom_Level::GetLevel()
{
	return Level;
}

void AEscapeRoom_Level::SetLevel(int32 newLevel)
{
	Level = newLevel;
}

void AEscapeRoom_Level::SetHints(int32 newLevel)
{
	
}

void AEscapeRoom_Level::ShowHint_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, GWorld->DeltaTimeSeconds, FColor::Yellow, FString::Printf(TEXT("SHOWING LEVEL 2 HINT")) );
	if(IsValid(HintWidgetClass))
	{
		if(HintWidget == nullptr)
		{
			HintWidget = Cast<UHintWidget>(CreateWidget(GetWorld(), HintWidgetClass));
			if(HintWidget != nullptr)
			{
				HintWidget->AddToViewport();
				HintWidget->PrintText(Hints[HintIndex]);
				HintIndex++;
				if(HintIndex >= Hints.Num())
				{
					HintIndex = 0;
				}
			}
		}
		else{
			HintWidget->SetVisibility(ESlateVisibility::Visible);
			HintWidget->PrintText(Hints[HintIndex]);
			if(HintIndex >= Hints.Num())
			{
				HintIndex = 0;
			}
		}
	}

}




bool AEscapeRoom_Level::ManageLevel(int32 NewLevel)
{
	if(NewLevel > Level)
	{
		SpawnCompletedLevelHint();
	}
	return false;
}


void AEscapeRoom_Level::SpawnCompletedLevelHint()
{
	
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, FString::Printf(TEXT("SpawnCompletedLevelHint")));

	if(IsValid(UVTextCompletedHintClass) && SpawnPoint !=  nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, FString::Printf(TEXT("IS VALID")));
		FVector Location = SpawnPoint->GetComponentLocation();
		FRotator Rotation = SpawnPoint->GetComponentRotation();

		UVTextCompletedHint = GetWorld()->SpawnActor<AActor>(UVTextCompletedHintClass, Location, Rotation);
		// UVTextCompletedHint->AttachToActor(this);
		UVTextCompletedHint->AttachToComponent( RootComponent ,FAttachmentTransformRules::SnapToTargetIncludingScale);

		// Projectile->SetOwner(this);
	}
	else {
		if(!IsValid(UVTextCompletedHintClass))
		{
			GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, FString::Printf(TEXT("UVTextCompletedHintClass not valid")));
		}
		if(SpawnPoint ==  nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, FString::Printf(TEXT("SpawnPoint not valid")));
		}

	}	

}
