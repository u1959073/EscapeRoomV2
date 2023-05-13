// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EscapeRoom_Level.h"
#include "EscapeRoom_Level_5.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPEROOMV2_API AEscapeRoom_Level_5 : public AEscapeRoom_Level
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	AEscapeRoom_Level_5();
	virtual void Tick(float DeltaTime) override;
	virtual bool ManageLevel(int32 NewLevel) override;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetWarningLight(bool IsRight);

	virtual void SetHints(int32 newLevel) override;


private:

	UPROPERTY(EditDefaultsOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UEscapeRoom_CardinalComponent* CompassComponent;


};
