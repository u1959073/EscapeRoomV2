// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EscapeRoom_BalancerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOMV2_API UEscapeRoom_BalancerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEscapeRoom_BalancerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetMovingScene(USceneComponent* SceneToMove);
	void Disable();
	void Enable();

private: 

	//Methods
	void Move();

	//Attributes
	UPROPERTY()
	USceneComponent* Scene;

	UPROPERTY(EditAnywhere, Category="Movement")
	float Speed = 20.f;

		
};
