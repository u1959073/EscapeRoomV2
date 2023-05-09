// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeRoom_UVCode.h"

// Sets default values
AEscapeRoom_UVCode::AEscapeRoom_UVCode()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Level = 1;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Scene;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(Scene);

}

// Called when the game starts or when spawned
void AEscapeRoom_UVCode::BeginPlay()
{
	Super::BeginPlay();
	SetActorTickEnabled(true);

	FTransform SocketTransform = BaseMesh->GetSocketTransform(TEXT("UVSpriteSocket"));
	UVSpriteCode = GetWorld()->SpawnActor<AActor>(UVSpriteCodeClass, SocketTransform);
	if(UVSpriteCode != nullptr)
	{
		UVSpriteCode->AttachToComponent( BaseMesh , FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("UVSpriteSocket"));
		UVSpriteCode->SetOwner(this);
	}
	
}

// Called every frame
void AEscapeRoom_UVCode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


bool AEscapeRoom_UVCode::ManageLevel(int32 NewLevel)
{
	IsActive = Level == NewLevel;
	SetActorTickEnabled(true);
	return IsActive;
}

