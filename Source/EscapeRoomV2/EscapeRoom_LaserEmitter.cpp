// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeRoom_LaserEmitter.h"
#include "Components/ArrowComponent.h"

// Sets default values
AEscapeRoom_LaserEmitter::AEscapeRoom_LaserEmitter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	EmitterRoot = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EmitterRoot"));
	RootComponent = EmitterRoot;

	Emitter = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Emitter"));
	Emitter->SetupAttachment(EmitterRoot);

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(Emitter);

}

// Called when the game starts or when spawned
void AEscapeRoom_LaserEmitter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEscapeRoom_LaserEmitter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// TODO: afegir un delay amb els timers de c++ perquè fer aquesta funció a cada tick és molt costós

	
	CastLight(Arrow->GetComponentLocation(),Arrow->GetForwardVector(), Distance );

}

void AEscapeRoom_LaserEmitter::CastLight(FVector CastOrigin, FVector CastDirection, float CastDistance)
{
	// FVector Start = WorldLocation;
	FVector CastEnd = CastDirection*CastDistance + CastOrigin;

	// FHitResult HitResult;
	FCollisionShape Sphere = FCollisionShape::MakeSphere(0.5);
	FHitResult HitResult;
	// GetWorld()->LineTraceSingleByObjectType(OutHit, Start, End,);


	DrawDebugLine
	(
		GetWorld(),
		CastOrigin,
		CastEnd,
		FColor::Red
		// bool bPersistentLines,
		// float LifeTime,
		// uint8 DepthPriority,
		// float Thickness 
	); 

	bool HasHit = GetWorld()->SweepSingleByChannel(
		HitResult, 
		CastOrigin, CastEnd,
		FQuat::Identity,
		ECC_GameTraceChannel1,
		Sphere
	);



	if(HasHit){
		DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 0.5, 10, FColor::Green, false, 5);

		if(HitResult.GetActor()->ActorHasTag("light"))
		{
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Yellow, (TEXT("HitActorInCondition %s"), *HitResult.GetActor()->GetActorNameOrLabel()));
		}

	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Yellow, TEXT("No hit"));	
	}

}