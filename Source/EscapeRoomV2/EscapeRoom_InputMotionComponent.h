// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EscapeRoom_InputMotionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOMV2_API UEscapeRoom_InputMotionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEscapeRoom_InputMotionComponent();
	UEscapeRoom_InputMotionComponent(USceneComponent * SceneToMove);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void SetMovingScene(USceneComponent* SceneToMove);


private: 

	//Methods
	void MoveMesh() const;



	//Attributes
	UPROPERTY()
	USceneComponent* Scene;

	APlayerController* PlayerControllerRef;

	UPROPERTY(EditAnywhere, Category="Movement")
	float Speed = 10.f;


		
};
