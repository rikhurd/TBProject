// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatTurnSystemManager.h"
#include "GameplayAbilityBase.h"

void UCombatTurnSystemManager::SetAbilityToQueue(UGameplayAbilityBase* Ability)
{
	AbilityQueue.Add(Ability);
}

TArray<UGameplayAbilityBase*> UCombatTurnSystemManager::SortAbilityQueue()
{
	AbilityQueue.Sort();

	return AbilityQueue;
}
