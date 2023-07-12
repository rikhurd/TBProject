// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "TBGameMode.generated.h"

/**
 * 
 */

UCLASS(Config = Game, Meta = (ShortTooltip = "The base game mode class used by this project."))
class TBS_PROJECT_API ATBGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	ATBGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};
