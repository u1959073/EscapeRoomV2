// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EscapeRoom_Level.generated.h"

UCLASS()
class ESCAPEROOMV2_API AEscapeRoom_Level : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEscapeRoom_Level();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual bool ManageLevel(int32 currentLevel);
	virtual void SetLevel(int32 newLevel);
	virtual int32 GetLevel();

protected: 
	
	UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class USpotLightComponent* SpotLight;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true"))
	bool IsActive;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true"))
	int32 Level;

};
