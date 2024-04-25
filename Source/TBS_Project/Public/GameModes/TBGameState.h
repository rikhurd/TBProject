// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"

#include "GameModes/TBGameStateChangeInterface.h"

#include "TBGameState.generated.h"

/**
 * 
 */
/* Delegate to progress abilities.
Since abilities always progress further 'this'Progress' naming conventions is used */
DECLARE_MULTICAST_DELEGATE(FProgressCombatAbilitiesSignature);

UCLASS()
class TBS_PROJECT_API ATBGameState : public AGameStateBase, public ITBGameStateChangeInterface
{
	GENERATED_BODY()

public:

	/**
	Called on actors which are a part of the combat encounter
		- When called on countdowns Action Speed variable for when to use ability
		- Actors are not limited to characters there are possibility of calling other types of actors.
			- Examples of this are:
				- Environmental actors: Crumbling buildings which would eventually fall due to player/enemy damage to the building
				- Abilities that linger in the field: Bow and arrow abilities that possibly have travel time (or ricochet around).
					Spells that linger or possibly summons
	*/
	FProgressCombatAbilitiesSignature ProgressCombatAbilitiesDelegate;

	/** Game State Change Interface implementation
	CHANGE THIS LATER FOR A DELEGATE(?)*/
	virtual void SetGameStateMode_Implementation(EGameStateMode GameMode) override;

	/** Sets up combat mode when entering combat zone. */
	UFUNCTION(BlueprintCallable)
		void SetupCombatMode();

	/** Sets up exploration mode usually when leaving combat. */
	UFUNCTION(BlueprintCallable)
		void SetupExplorationMode();

	/** Progresses combat abilities execute time. */
	UFUNCTION(BlueprintCallable)
		void ProgressCombatAbilities();
};
