 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EscapeRoom_Spawner.generated.h"

UCLASS()
class ESCAPEROOMV2_API AEscapeRoom_Spawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEscapeRoom_Spawner();
	void SetChildActor(class UARCandidateImage* DetectedImage);


	bool ChildActorHasTag(FName tag);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UChildActorComponent* ChildActor;

	// UPROPERTY(EditDefaultsOnly, Category = "BP_Class")
	// UClass* provaClasse;


	UPROPERTY(EditAnywhere, Category = "Variables")
	TMap<class UARCandidateImage*,UClass*> SpawnableImages;




};
