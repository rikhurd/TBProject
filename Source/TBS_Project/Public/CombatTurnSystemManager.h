// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "CombatTurnSystemManager.generated.h"


/**
 * 
 */
class GameplayAbilityBase;

UCLASS()
class TBS_PROJECT_API UCombatTurnSystemManager : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Combat Turn System Variables")
	TArray<UGameplayAbilityBase*> AbilityQueue;

	/** Set neighbor tiles */
	UFUNCTION(BlueprintCallable, Category = "Combat Turn System functions")
	void SetAbilityToQueue(UGameplayAbilityBase* Ability);

	/** Set neighbor tiles */
	UFUNCTION(BlueprintCallable, Category = "Combat Turn System functions")
	TArray<UGameplayAbilityBase*>  SortAbilityQueue();

};
