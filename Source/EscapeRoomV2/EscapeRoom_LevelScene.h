// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "EscapeRoom_LevelScene.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOMV2_API UEscapeRoom_LevelScene : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEscapeRoom_LevelScene();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual bool ManageLevel(int32 currentLevel);
	virtual void SetLevel(int32 newLevel);
	virtual int32 GetLevel();

protected:
	bool IsActive;
	int32 Level;
		
};
