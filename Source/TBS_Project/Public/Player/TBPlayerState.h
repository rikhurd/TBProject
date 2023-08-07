// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"

#include "GameModes/TBGameStateChangeInterface.h"

#include "TBPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class TBS_PROJECT_API ATBPlayerState : public APlayerState, public ITBGameStateChangeInterface
{
	GENERATED_BODY()
	
public:

	/* Array that contains references to player's team members */
	UPROPERTY(BlueprintReadOnly, Category = "Player team settings")
		TArray<APawn*> PlayerTeamPawns;

	/** Set array of actors which are a part of the player's team */
	UFUNCTION(BlueprintCallable, Category = "Player team settings")
		TArray<APawn*> SetPlayerTeamPawns();

	/* Delegates combat mode init into player's controller and controlled character */
	virtual void CombatModeInit_Implementation() override;
};
