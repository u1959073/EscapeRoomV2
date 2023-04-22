// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EscapeRoom_ReactToTrigger.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEscapeRoom_ReactToTrigger : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ESCAPEROOMV2_API IEscapeRoom_ReactToTrigger
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual bool ReactToTrigger();

private: 

	TArray<AActor*> AffectedActors; 

};
