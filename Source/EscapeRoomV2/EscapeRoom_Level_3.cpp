// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeRoom_Level_3.h"
#include "Components/SceneComponent.h"
#include "EscapeRoom_LaserEmitter.h"
#include "EscapeRoom_LaserSensor.h"
#include "EscapeRoom_InputMotionComponent.h"


AEscapeRoom_Level_3::AEscapeRoom_Level_3()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Scene;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(Scene);

	MirrorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mirror Mesh"));
	MirrorMesh->SetupAttachment(Scene);

	Mirror_1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mirror 1"));
	Mirror_1->SetupAttachment(Scene);

	StaticMirrorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mirror Mesh"));
	StaticMirrorMesh->SetupAttachment(Scene);

	LaserEmitterInputMotionComp = CreateDefaultSubobject<UEscapeRoom_InputMotionComponent>(TEXT("Laser Emitter Input Motion Component"));
	LaserSensorInputMotionComp = CreateDefaultSubobject<UEscapeRoom_InputMotionComponent>(TEXT("Laser Sensor Input Motion Component"));
	MirrorInputMotionComp = CreateDefaultSubobject<UEscapeRoom_InputMotionComponent>(TEXT("Mirror Input Motion Component"));
	



}

// Called when the game starts or when spawned
void AEscapeRoom_Level_3::BeginPlay()
{
	Super::BeginPlay();
	// SetActorTickEnabled(false);

	GetRootComponent();

	FTransform SocketTransform = BaseMesh->GetSocketTransform(TEXT("LaserEmitterSocket"));
	LaserEmitter = GetWorld()->SpawnActor<AEscapeRoom_LaserEmitter>(LaserEmitterClass, SocketTransform);

	if(LaserEmitter != nullptr)
	{
		LaserEmitterInputMotionComp->SetMovingScene(LaserEmitter->GetRootComponent());
		LaserEmitter->AttachToComponent( BaseMesh , FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("LaserEmitterSocket"));
		LaserEmitter->SetOwner(this);
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



	LaserSensor = GetWorld()->SpawnActor<AEscapeRoom_LaserSensor>(LaserSensorClass);

}

// Called every frame
void AEscapeRoom_Level_3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// TODO: afegir un delay amb els timers de c++ perquè fer aquesta funció a cada tick és molt costós
	
}


