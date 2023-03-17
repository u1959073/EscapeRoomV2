// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EscapeRoom_InputMotion.generated.h"

UCLASS()
class ESCAPEROOMV2_API AEscapeRoom_InputMotion : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEscapeRoom_InputMotion();


private:
	void MoveMesh() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input

private: 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Puzzle",  meta = (AllowPrivateAccess = "true") )
	UStaticMeshComponent* BaseMesh;

	APlayerController* PlayerControllerRef;


	UPROPERTY(EditAnywhere, Category="Movement")
	float Speed = 10.f;



};
