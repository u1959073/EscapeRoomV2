// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeRoom_Level_1.h"

AEscapeRoom_Level_1::AEscapeRoom_Level_1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Level = 1;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Scene;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(Scene);

}

void AEscapeRoom_Level_1::BeginPlay()
{
	Super::BeginPlay();
	// SetActorTickEnabled(false);
	
	SetActorTickEnabled(true);

	// FTransform SocketTransform = BaseMesh->GetSocketTransform(TEXT("UVTextSocket"));
	// UVTextCode = GetWorld()->SpawnActor<AActor>(UVTextCodeClass, SocketTransform);
	// if(UVTextCode != nullptr)
	// {
	// 	UVTextCode->AttachToComponent( BaseMesh , FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("UVTextSocket"));
	// 	UVTextCode->SetOwner(this);
	// }

	// SocketTransform = BaseMesh->GetSocketTransform(TEXT("UVLightSocket"));
	// UVLight = GetWorld()->SpawnActor<AActor>(UVLightClass, SocketTransform);
	// if(UVLight != nullptr)
	// {
	// 	UVLight->AttachToComponent( BaseMesh , FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("UVLightSocket"));
	// 	UVLight->SetOwner(this);
	// }



}

void AEscapeRoom_Level_1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}


bool AEscapeRoom_Level_1::ManageLevel(int32 NewLevel)
{
	IsActive = Level == NewLevel;
	SetWarningLight(Level < NewLevel);
	SetActorTickEnabled(true);
	return IsActive;
}
