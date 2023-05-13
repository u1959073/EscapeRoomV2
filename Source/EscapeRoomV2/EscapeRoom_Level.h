// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "I_EscapeRoom_Dialog.h"
#include "EscapeRoom_Level.generated.h"

UCLASS()
class ESCAPEROOMV2_API AEscapeRoom_Level : public AActor, public II_EscapeRoom_Dialog
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
	virtual void SetHints(int32 newLevel);
	virtual void SpawnCompletedLevelHint();

	virtual int32 GetLevel();

	UFUNCTION(BlueprintCallable, Category="Dialog")
	void ShowHint_Implementation() override;

protected: 
	
	UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class USpotLightComponent* SpotLight;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true"))
	bool IsActive;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true"))
	int32 Level;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TArray<FString> Hints;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true"))
	int32 HintIndex;

	UPROPERTY(VisibleInstanceOnly, Category = "Widget", meta = (AllowPrivateAccess = "true"))
	class UHintWidget* HintWidget;

	UPROPERTY(EditDefaultsOnly, Category = "Class Types", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class UUserWidget> HintWidgetClass;


	// Last Hint ( code number shown with UVLight spawned when level is completed )
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* SpawnPoint;

	UPROPERTY()
	class AActor* UVTextCompletedHint;

	UPROPERTY(EditDefaultsOnly, Category = "Class Types", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class AActor> UVTextCompletedHintClass;


};
