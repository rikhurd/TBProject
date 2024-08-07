// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/TBGameState.h"
#include "GameFramework/PlayerState.h"


/* Calls setup function with the given enum choice */
void ATBGameState::SetGameStateMode_Implementation(EGameStateMode GameMode)
{
	switch (GameMode)
	{
	case EGameStateMode::Combat:
		SetupCombatMode();
		break;
	case EGameStateMode::Exploration:
		SetupExplorationMode();
		break;
	default:
		break;
	}
}

/* Setups combat mode for the current players */
void ATBGameState::SetupCombatMode()
{
	/* Iterates whole player list which size is 1 because of only singleplayer is implemented
		- Later could be fetch from game's start menu when playing singleplayer -> PlayerState is set as a variable*/
	for (APlayerState* PlayerState : PlayerArray)
	{
		/* Checks if interface is implemented */
		if (PlayerState->Implements<UTBGameStateChangeInterface>())
		{
			/* Sends call on the player state */
			ITBGameStateChangeInterface::Execute_CombatModeInit(PlayerState);
		}
	}
}

void ATBGameState::SetupExplorationMode()
{
}

/* Calling this function broadcasts turn completion into its binded functions. */
void ATBGameState::ProgressCombatAbilities()
{
	ProgressCombatAbilitiesDelegate.Broadcast();
}
