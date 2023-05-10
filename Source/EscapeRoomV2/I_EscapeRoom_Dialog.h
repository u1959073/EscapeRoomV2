// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h" 	
#include "Containers/Array.h"
#include "Containers/UnrealString.h"
#include "I_EscapeRoom_Dialog.generated.h"

// This class does not need to be modified.
UINTERFACE(BlueprintType)
class UI_EscapeRoom_Dialog : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ESCAPEROOMV2_API II_EscapeRoom_Dialog
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	// UFUNCTION(BlueprintCallable)
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Dialog")
	void ShowHint();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Dialog")
	void HideHint();

};
