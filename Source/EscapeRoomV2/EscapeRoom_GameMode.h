// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EscapeRoom_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPEROOMV2_API AEscapeRoom_GameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;


public:	
	// Called every frame

	AEscapeRoom_GameMode();

	UFUNCTION(BlueprintImplementableEvent)
	void ToggleGlobalLight();

	void ManageGameLevel(int32 Level);


	virtual void Tick(float DeltaTime) override;

private: 

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Config", meta = (AllowPrivateAccess = "true"))
	class UARSessionConfig* EscapeRoom_SessionConfig;

	UPROPERTY(EditDefaultsOnly, Category = "BP_Class")
	TSubclassOf<class UGoogleARCoreAugmentedImage> AugmentedImageClass;

	UPROPERTY(EditDefaultsOnly, Category = "BP_Class")
	TSubclassOf<class AEscapeRoom_Spawner> SpawnerClass;

	UPROPERTY(EditDefaultsOnly, Category = "BP_Class")
	TSubclassOf<class UARTrackedImage> TrackedImageClass;

	UPROPERTY(VisibleAnywhere, Category = "Variables")
	TMap<class UARCandidateImage*, class AEscapeRoom_Spawner*> SpawnedImages;
	// TMap<class UARCandidateImage*, class AEscapeRoom_Spawner*> SpawnedImages;

	UPROPERTY(VisibleAnywhere, Category = "Variables")
	int32 CurrentLevel;


	TArray<class UARTrackedImage*> AuxTrackedImages;
	// APlayerController* PlayerControllerRef;	


	
};
