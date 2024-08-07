// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TBAbilityInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UTBAbilityInterface : public UInterface
{
	GENERATED_BODY()
};


class ATileBase;
/**
 * 
 */
class TBS_PROJECT_API ITBAbilityInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	// Sets Game State Mode mainly used in TBGameState to switch between Combat and Exploration mode
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Ability Tile Select Functions")
	void AbilityTargetTile(AActor* SelectedTarget);
};
