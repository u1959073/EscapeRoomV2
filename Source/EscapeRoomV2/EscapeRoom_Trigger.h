// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "EscapeRoom_Trigger.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ESCAPEROOMV2_API UEscapeRoom_Trigger : public UBoxComponent
{
	GENERATED_BODY()

public:
	UEscapeRoom_Trigger();


public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	bool IsPressed() const;

private:
	UPROPERTY(EditAnywhere)
	FName AcceptableActorTag;

	UPROPERTY(EditAnywhere)
	bool Pressed;


	AActor* GetAcceptableActor() const;
 
};
