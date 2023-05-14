// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "EscapeRoom_Button.generated.h"

UCLASS()
class ESCAPEROOMV2_API AEscapeRoom_Button : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEscapeRoom_Button();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Events")
	void HandleInputTouch(USceneComponent* ButtonMesh);

private:
	// void ButtonPressed(ETouchIndex::Type FingerIndex, UPrimitiveComponent* TouchedComponent);


private:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ButtonMesh;



	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* Scene;

	UPROPERTY(EditDefaultsOnly, Category = "BP_Class")
	TSubclassOf<class AActor> ButtonClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Variables", meta = (AllowPrivateAccess = "true"))
	bool lightOn = false;




};
