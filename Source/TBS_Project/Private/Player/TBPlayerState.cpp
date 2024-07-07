// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TBPlayerState.h"

TArray<APawn*> ATBPlayerState::SetPlayerTeamPawns()
{
	PlayerTeamPawns.Empty();
	PlayerTeamPawns.Add(GetPawn());
	return PlayerTeamPawns;
}
/* List here functions that need to setup things when moving into an encounter (battle) */
void ATBPlayerState::CombatModeInit_Implementation()
{

	if (GetPawn()->Implements<UTBGameStateChangeInterface>()) ITBGameStateChangeInterface::Execute_CombatModeInit(GetPawn());
	if (GetPlayerController()->Implements<UTBGameStateChangeInterface>()) ITBGameStateChangeInterface::Execute_CombatModeInit(GetPlayerController());
}
