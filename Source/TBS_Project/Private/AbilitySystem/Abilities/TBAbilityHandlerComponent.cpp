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

	GameState = GetWorld() != NULL ? GetWorld()->GetGameState<ATBGameState>() : NULL;
	// Add ref of an ability here that is going to be used by the character

	//Ref of the speed of the ability to use the countdown for the combat system to countdown
}

void UTBAbilityHandlerComponent::SetNewAbility(UGameplayAbilityBase* Ability)
{
	CurrentAbility = Ability;

	GameState->ProgressCombatAbilitiesDelegate.AddUObject(this,&UTBAbilityHandlerComponent::ProgressAbilityState);
	//SetAbilityToArray();
}

void UTBAbilityHandlerComponent::ProgressAbilityState()
{
	UE_LOG(LogTemp, Warning, TEXT("Bound function called on: %s"), *this->GetName());
}

