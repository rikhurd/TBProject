// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TBGameStateChangeInterface.generated.h"

// This class does not need to be modified.

/* Enum for switching between game states.
Mostly using enums because of blueprints */
UENUM(BlueprintType)
enum class EGameStateMode : uint8
{
	Combat UMETA(DisplayName = "Combat"),
	Exploration UMETA(DisplayName = "Exploration")
};

UINTERFACE(MinimalAPI, Blueprintable)
class UTBGameStateChangeInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TBS_PROJECT_API ITBGameStateChangeInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	// Sets Game State Mode mainly used in TBGameState to switch between Combat and Exploration mode
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Game State Change Functions")
		void SetGameStateMode(EGameStateMode GameMode);

	// Initializes Combat mode. For example sets up start tile for player characters, disables free 3D Movement and initializes necessary data needed for subsystems
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Game State Change Functions")
		void CombatModeInit();

	// Initializes Eploration mode. Enables free 3D movement etc.
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Game State Change Functions")
		void ExplorationModeInit();

	// Initializes Eploration mode. Enables free 3D movement etc.
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Game State Change Functions")
		void GetPlayerStatePawns();
};
