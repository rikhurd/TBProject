// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AbilitySystem/TBAbilityInterface.h"
#include "TBPlayerController.generated.h"

/**
 * 
 */

class ATBCharacterBase;
class UInputMappingContext;
class UEnhancedInputLocalPlayerSubsystem;


UCLASS()
class TBS_PROJECT_API ATBPlayerController : public APlayerController, public ITBAbilityInterface
{
	GENERATED_BODY()

public:

	/** Adding new party members */
	UFUNCTION(BlueprintCallable, Category = "Player")
	bool AddPartyCharacter(ATBCharacterBase* NewCharacter);

	/** Contains party members */
	UPROPERTY(BlueprintReadWrite, Category = "Player")
	TArray<TObjectPtr<ATBCharacterBase>> PlayerPartyArray;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, Category = "Tile select")
	bool SelectTileForAbility = false;

};

