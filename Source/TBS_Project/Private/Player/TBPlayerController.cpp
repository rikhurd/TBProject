// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TBPlayerController.h"
#include "Character/TBCharacterBase.h"

bool ATBPlayerController::AddPartyCharacter(ATBCharacterBase* NewCharacter)
{
	if (!NewCharacter) {
		return false;
	}

	PlayerPartyArray.AddUnique(NewCharacter);

	return true;
}