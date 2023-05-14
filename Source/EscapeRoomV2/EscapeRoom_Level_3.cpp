// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeRoom_Level_3.h"
#include "Components/SceneComponent.h"
#include "EscapeRoom_LaserEmitter.h"
#include "EscapeRoom_LaserSensor.h"
#include "EscapeRoom_GameMode.h"
#include "Kismet/GameplayStatics.h"

#include "EscapeRoom_InputMotionComponent.h"


AEscapeRoom_Level_3::AEscapeRoom_Level_3()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Level = 3;


	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Scene;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(Scene);


	Mirror_1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mirror 1"));
	Mirror_1->SetupAttachment(Scene);


	LaserEmitterInputMotionComp = CreateDefaultSubobject<UEscapeRoom_InputMotionComponent>(TEXT("Laser Emitter Input Motion Component"));
	LaserSensorInputMotionComp = CreateDefaultSubobject<UEscapeRoom_InputMotionComponent>(TEXT("Laser Sensor Input Motion Component"));
	MirrorInputMotionComp = CreateDefaultSubobject<UEscapeRoom_InputMotionComponent>(TEXT("Mirror Input Motion Component"));

}

// Called when the game starts or when spawned
void AEscapeRoom_Level_3::BeginPlay()
{
	Super::BeginPlay();
	// SetActorTickEnabled(false);


	FTransform SocketTransform = BaseMesh->GetSocketTransform(TEXT("LaserEmitterSocket"));
	LaserEmitter = GetWorld()->SpawnActor<AEscapeRoom_LaserEmitter>(LaserEmitterClass, SocketTransform);
	

	if(LaserEmitter != nullptr)
	{
		LaserEmitterInputMotionComp->SetMovingScene(LaserEmitter->GetRootComponent());
		LaserEmitter->AttachToComponent( BaseMesh , FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("LaserEmitterSocket"));
		LaserEmitter->SetOwner(this);
		LaserEmitter->SetLevel(Level);
	}

	SocketTransform = BaseMesh->GetSocketTransform(TEXT("LaserSensorSocket"));
	LaserSensor = GetWorld()->SpawnActor<AEscapeRoom_LaserSensor>(LaserSensorClass, SocketTransform);

	if(LaserSensor != nullptr)
	{
		LaserSensorInputMotionComp->SetMovingScene(LaserSensor->GetRootComponent());
		LaserSensor->AttachToComponent( BaseMesh , FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("LaserSensorSocket"));
		LaserSensor->SetOwner(this);
	}

	if(Mirror_1 != nullptr)
	{
		MirrorInputMotionComp->SetMovingScene(Mirror_1);
	}


}

// Called every frame
void AEscapeRoom_Level_3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if(LaserEmitter->HasActiveSensor())
	{
		
		AEscapeRoom_GameMode *GameMode = Cast<AEscapeRoom_GameMode>(UGameplayStatics::GetGameMode(this));
		if(GameMode != nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Yellow, FString::Printf(TEXT("HandleInputTouch")));
			GameMode->ManageGameLevel(5);
		}
		LaserEmitterInputMotionComp->Disable();
		LaserSensorInputMotionComp->Disable();
		MirrorInputMotionComp->Disable();

	}

	// TODO: afegir un delay amb els timers de c++ perquè fer aquesta funció a cada tick és molt costós
	
}

bool AEscapeRoom_Level_3::ManageLevel(int32 NewLevel)
{
	IsActive = Level == NewLevel;
	SetActorTickEnabled(IsActive);
	SetHints(NewLevel);
	LaserEmitter->ManageLevel(NewLevel);
	return IsActive;
}

void AEscapeRoom_Level_3::SetHints(int32 newLevel)
{
	Hints.Empty();
	HintIndex = 0;
	if(newLevel < Level)
	{
		Hints.Emplace(TEXT("To fire the laser and light up the way,\nPress the buttons in the correct array."));
		Hints.Emplace(TEXT("Buttons must be pushed with care,\nTo activate the laser beam in the air"));

	}
	else if(newLevel == Level)
	{
		Hints.Emplace(TEXT("The laser beam needs a guiding hand,\nBounce it off mirrors to hit the sensor stand."));
		Hints.Emplace(TEXT("The sensor waits for the laser's shine,\nUse mirrors to guide it and align"));
	}
	else if(newLevel > Level)
	{
		Hints.Emplace(TEXT("This level has already been solved."));
	}
}


