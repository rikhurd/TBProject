// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TBPlayerState.h"

void ATBPlayerState::CombatModeInit_Implementation()
{

	if (GetPawn()->Implements<UTBGameStateChangeInterface>())
	{
		ITBGameStateChangeInterface::Execute_CombatModeInit(GetPawn());
	}
}
