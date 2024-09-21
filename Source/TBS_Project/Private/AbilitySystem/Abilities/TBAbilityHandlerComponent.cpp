// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/TBAbilityHandlerComponent.h"
#include "AbilitySystem/Abilities/TBGameplayAbilityBase.h"
#include "GameModes/TBGameState.h"

// Sets default values for this component's properties
UTBAbilityHandlerComponent::UTBAbilityHandlerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

bool UTBAbilityHandlerComponent::SetNewAbility(UTBGameplayAbilityBase* Ability)
{
	if (!IsValid(GameState))
	{
		GameState = GetWorld() != NULL ? GetWorld()->GetGameState<ATBGameState>() : NULL;
	}
	check(GameState);

	if (!GameState->ProgressCombatAbilitiesDelegate.IsBoundToObject(this))
	{
		CurrentAbility = Ability;
		/* Bind new set ability into the delegate that progress ability. */
		GameState->ProgressCombatAbilitiesDelegate.AddUObject(this, &UTBAbilityHandlerComponent::ProgressAbilityState);
	}

	// Bool can later be used to check for confirmation on overwriting current abilities
	return true;
}

void UTBAbilityHandlerComponent::ProgressAbilityState()
{
	UE_LOG(LogTemp, Warning, TEXT("Bound function called on: %s with Ability %s2"), *this->GetName(), *CurrentAbility->GetName());
}
