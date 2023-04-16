// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeRoom_LaserEmitter.h"
#include "Components/ArrowComponent.h"
#include "Materials/MaterialInterface.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"


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
	FCollisionQueryParams TraceParams = FCollisionQueryParams();
	TraceParams.bReturnFaceIndex=true;
	TraceParams.bTraceComplex =true;

	bool HasHit = GetWorld()->LineTraceSingleByChannel(
		HitResult,
		CastOrigin,CastEnd,
		ECC_GameTraceChannel1,
		TraceParams
	);


	if(HasHit){
		DrawDebugLine(GetWorld(),CastOrigin,HitResult.ImpactPoint,FColor::Red); 
		DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 0.5, 10, FColor::Green, false, 5);
		// HitResult.GetComponent()->GetMaterialFromCollisionFaceIndex(HitResult.FaceIndex,HitResult.SectionIndex);

		HitResult.GetComponent()->GetMaterial(HitResult.FaceIndex);
		FString ComponentName = UKismetSystemLibrary::GetDisplayName(HitResult.GetComponent());
		GEngine->AddOnScreenDebugMessage(-1, GWorld->DeltaTimeSeconds, FColor::Red, FString::Printf(TEXT("Collision component INDEX: %i"), HitResult.FaceIndex));


		int32 SectionIndex;
		UMaterialInterface* CollisionMaterial = HitResult.GetComponent()->GetMaterialFromCollisionFaceIndex(HitResult.FaceIndex, SectionIndex);
		// UMaterialInterface* CollisionMaterial = HitResult.GetComponent()->GetMaterial(HitResult.FaceIndex);

		if(CollisionMaterial != nullptr && MirrorMaterial != nullptr)
		{
			if(CollisionMaterial == MirrorMaterial)
			{
				GEngine->AddOnScreenDebugMessage(-1, GWorld->DeltaTimeSeconds, FColor::Yellow, (TEXT("HIT MIRROR")));
				CastLight(
					HitResult.ImpactPoint, 
					UKismetMathLibrary::MirrorVectorByNormal(CastDirection, HitResult.ImpactNormal), 
					CastDistance-(FVector::Distance(CastOrigin, HitResult.ImpactPoint))
				);
			}
			else 
			{
				GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Yellow, (TEXT("HIT NO MIRROR")));
			}

		}  
	}
	else {
		DrawDebugLine(GetWorld(),CastOrigin,CastEnd,FColor::Red); 
	}

}