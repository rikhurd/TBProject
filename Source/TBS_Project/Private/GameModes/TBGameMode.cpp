// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/TBGameMode.h"

#include "GameModes/TBGameState.h"
#include "GameModes/TBGameSession.h"
#include "Player/TBPlayerController.h"
#include "Player/TBPlayerState.h"
#include "Character/TBCharacterBase.h"


ATBGameMode::ATBGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	
	GameStateClass = ATBGameState::StaticClass();
	GameSessionClass = ATBGameState::StaticClass();


	PlayerControllerClass = ATBPlayerController::StaticClass();
	/*
	ReplaySpectatorPlayerControllerClass = ALyraReplayPlayerController::StaticClass();
	*/
	PlayerStateClass = ATBPlayerState::StaticClass();

	DefaultPawnClass = ATBCharacterBase::StaticClass();
	/*
	HUDClass = ALyraHUD::StaticClass();*/
}