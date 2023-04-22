// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EscapeRoom_LevelStateManager.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEscapeRoom_LevelStateManager : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ESCAPEROOMV2_API IEscapeRoom_LevelStateManager
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void ManageLevelState(int level);

protected:

	class TArray<int32> Levels; 

private: 





};
