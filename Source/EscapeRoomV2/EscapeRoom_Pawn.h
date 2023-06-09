// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EscapeRoom_Pawn.generated.h"

UCLASS()
class ESCAPEROOMV2_API AEscapeRoom_Pawn : public APawn
{
	GENERATED_BODY()

private:


public:
	// Sets default values for this pawn's properties
	AEscapeRoom_Pawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category="Light")
	void ToggleFlashLight();

	UFUNCTION(BlueprintCallable, Category="Light")
	void SetDialogCollision(bool ActorDialog);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="Light")
	void OnHelpRequest();


private: 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UEscapeRoom_CardinalComponent* Compass;

	UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class USpotLightComponent* SpotFlashlight;

	UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* FlashlightCollisionComponent;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* DialogCollisionComponent;


	UPROPERTY(EditDefaultsOnly, Category = "BP_Class")
	TSubclassOf<class AActor> ButtonClass;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true"))
	APlayerController* PlayerControllerRef;


};
