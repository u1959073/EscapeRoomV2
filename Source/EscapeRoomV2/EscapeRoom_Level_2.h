// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EscapeRoom_Level.h"
#include "EscapeRoom_Level_2.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPEROOMV2_API AEscapeRoom_Level_2 : public AEscapeRoom_Level
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	AEscapeRoom_Level_2();
	virtual void Tick(float DeltaTime) override;
	virtual bool ManageLevel(int32 NewLevel) override;

private:

	UPROPERTY(EditDefaultsOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* Scene;

	UPROPERTY(EditDefaultsOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* CollisionBox_1;

	UPROPERTY(EditDefaultsOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* CollisionBox_2;

	UPROPERTY()
	class AEscapeRoom_Balancer* Balancer_1;

	UPROPERTY()
	class AEscapeRoom_Balancer* Balancer_2;


	UPROPERTY(EditDefaultsOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class AEscapeRoom_Balancer> BalancerClass;


};
