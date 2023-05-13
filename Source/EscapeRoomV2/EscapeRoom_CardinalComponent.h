// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EscapeRoom_CardinalComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOMV2_API UEscapeRoom_CardinalComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEscapeRoom_CardinalComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	bool IsNorth();
	bool IsSouth();
	bool IsEast();
	bool IsWest();



private: 

	FVector _tilt;
	FVector _rotation;
	FVector _gravity; 
	FVector _acceleration;
	APlayerController* PlayerControllerRef;
		
};
