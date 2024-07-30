// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TBPlayerController.generated.h"

/**
 * 
 */

class ATBCharacterBase;

UCLASS()
class TBS_PROJECT_API ATBPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Player")
	bool AddPartyCharacter(ATBCharacterBase* NewCharacter);

	//~ End IAbilitySystemInterface

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, Category = "Player")
	TArray<TObjectPtr<ATBCharacterBase>> PlayerPartyArray;

protected:

	/** Called for movement input
	void Move(const FInputActionValue& Value);

	/** Called for looking input 
	void Look(const FInputActionValue& Value);*/

};

