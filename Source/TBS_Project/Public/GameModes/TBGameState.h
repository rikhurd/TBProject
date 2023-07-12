// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"

#include "GameModes/TBGameStateChangeInterface.h"

#include "TBGameState.generated.h"

/**
 * 
 */

UCLASS()
class TBS_PROJECT_API ATBGameState : public AGameStateBase, public ITBGameStateChangeInterface
{
	GENERATED_BODY()

public:

	/** Game State Change Interface implementation */
	virtual void SetGameStateMode_Implementation(EGameStateMode GameMode) override;

	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
		void SetupCombatMode();

	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
		void SetupExplorationMode();

	/** Default scene root
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
		TObjectPtr<USceneComponent> DefaultSceneRoot;*/

	/** Please add a variable description 
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
		TEnumAsByte<E_GameStateModes> GameStateMode;*/

};
