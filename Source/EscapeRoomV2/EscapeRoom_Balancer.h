// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EscapeRoom_Level.h"
#include "EscapeRoom_Balancer.generated.h"

UCLASS()
class ESCAPEROOMV2_API AEscapeRoom_Balancer : public AEscapeRoom_Level
{
	GENERATED_BODY()
	
private:
	void Move();

public:	
	// Sets default values for this actor's properties
	AEscapeRoom_Balancer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// virtual bool ManageLevel(int32 NewLevel) override;


private: 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Puzzle",  meta = (AllowPrivateAccess = "true") )
	UStaticMeshComponent* MovingMesh;

	UPROPERTY(VisibleAnywhere, Category = "Movement")
	class UEscapeRoom_BalancerComponent* BalancerComponent; 


};
