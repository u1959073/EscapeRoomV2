// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EscapeRoom_Level.h"
#include "EscapeRoom_Level_3.generated.h"

/**
 * 
 */

UCLASS()
class ESCAPEROOMV2_API AEscapeRoom_Level_3 : public AEscapeRoom_Level
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	AEscapeRoom_Level_3();
	virtual void Tick(float DeltaTime) override;
	virtual bool ManageLevel(int32 NewLevel) override;
	virtual void SetHints(int32 newLevel) override;


private:



	UPROPERTY(EditDefaultsOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* Scene;


	UPROPERTY()
	class AEscapeRoom_LaserEmitter* LaserEmitter;

	UPROPERTY(EditDefaultsOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class AEscapeRoom_LaserEmitter> LaserEmitterClass;

	UPROPERTY(VisibleAnywhere, Category = "Movement")
	class UEscapeRoom_InputMotionComponent* LaserEmitterInputMotionComp; 



	UPROPERTY()
	class AEscapeRoom_LaserSensor* LaserSensor;

	UPROPERTY(EditDefaultsOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class AEscapeRoom_LaserSensor> LaserSensorClass;

	UPROPERTY(VisibleAnywhere, Category = "Movement")
	class UEscapeRoom_InputMotionComponent* LaserSensorInputMotionComp; 


	UPROPERTY(EditDefaultsOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* Mirror_1;
	UPROPERTY(VisibleAnywhere, Category = "Movement")
	class UEscapeRoom_InputMotionComponent* MirrorInputMotionComp; 






	
};
