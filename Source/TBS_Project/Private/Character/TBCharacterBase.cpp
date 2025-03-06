// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/TBCharacterBase.h"
#include "Grid/TileBase.h"
#include "AbilitySystem/TBAbilitySystemComponent.h"
#include "AbilitySystem/AttributeSets/TBCharacterAttributeSet.h"
#include "AbilitySystem/AttributeSets/TBAbilityAttributeSet.h"
#include "GameModes/TBGameState.h"
#include "AbilitySystem/Abilities/TBGameplayAbilityBase.h"
#include "AbilitySystem/Abilities/TBAbilityDataAsset.h"

ATBCharacterBase::ATBCharacterBase()
{
	AbilitySystemComponent = CreateDefaultSubobject<UTBAbilitySystemComponent>(TEXT("Ability System Component"));
}

void ATBCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	check(AbilitySystemComponent);
	//if (IsValid(AbilitySystemComponent))
		// Get the UTBCharacterAttributeSet from our Ability System Component. The Ability System Component will create and register one if needed.
		CharacterAttributeSet = AbilitySystemComponent->GetSet<UTBCharacterAttributeSet>();
}

class UAbilitySystemComponent* ATBCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

bool ATBCharacterBase::SetNewAbility(UTBGameplayAbilityBase* NewAbility, FGameplayAbilitySpecHandle NewAbilityHandle)
{
	if (!IsValid(GameState))
	{
		GameState = GetWorld() != NULL ? GetWorld()->GetGameState<ATBGameState>() : NULL;
	}
	check(GameState);
	GameState->ProgressCombatAbilitiesDelegate.IsBoundToObject(NewAbility);
	if (!GameState->ProgressCombatAbilitiesDelegate.IsBoundToObject(this))
	{
		CurrentAbilityHandle = NewAbilityHandle;
		/*
		if (IsValid(Ability->AbilityData))
		{

			CurrentAbilitySpeed = CurrentAbilityHandle->AbilityData->AbilityVariableData->ActionSpeed;
			*/
			/* Bind new set ability into the delegate that progress ability. */
		GameState->ProgressCombatAbilitiesDelegate.AddUObject(this, &ATBCharacterBase::ProgressAbilityState);
		/* }
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Ability %s does not have Ability data set"), CurrentAbilityHandle);
		}*/
	}

	// Bool can later be used to check for confirmation on overwriting current abilities
	return true;
}

bool ATBCharacterBase::RemoveAbilityFromUse()
{
	if (!IsValid(GameState))
	{
		GameState = GetWorld() != NULL ? GetWorld()->GetGameState<ATBGameState>() : NULL;
	}
	check(GameState);

	if (GameState->ProgressCombatAbilitiesDelegate.IsBoundToObject(this))
	{
		/* Remove bind from delegate. */
		//GameState->ProgressCombatAbilitiesDelegate.Remove(CurrentAbilityDelegate);
	}

	// Bool can later be used to check for confirmation on overwriting current abilities
	return true;
}


void ATBCharacterBase::ProgressAbilityState()
{
	UE_LOG(LogTemp, Warning, TEXT("Bound function called on: %s with Ability %s2"), *this->GetName(), CurrentAbilityHandle);

	GetAbilitySystemComponent()->TryActivateAbility(CurrentAbilityHandle);
/*
	if (CurrentAbilitySpeed >= 0)
	{
		GetAbilitySystemComponent()->TryActivateAbility(CurrentAbilityHandle);
	}
	else
	{
		CurrentAbilitySpeed--;
	}
	*/
}

bool ATBCharacterBase::AddAbilityAttributeSet(UTBAbilityAttributeSet* NewAbilityAttributeSet)
{
	AbilitySystemComponent->GetSpawnedAttributes_Mutable().AddUnique(NewAbilityAttributeSet);
	return false;
}

bool ATBCharacterBase::RemoveAbilityAttributeSet(UTBAbilityAttributeSet* OldAbilityAttributeSet)
{
	AbilitySystemComponent->GetSpawnedAttributes_Mutable().Remove(OldAbilityAttributeSet);
	return false;
}
