// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/TBGameplayAbilityBase.h"
#include "AbilitySystem/Abilities/TBAbilityHandlerComponent.h"
#include "AbilitySystem/Abilities/TBAbilityDataAsset.h"

bool UTBGameplayAbilityBase::AbilitySetup_Implementation(AActor* SelectedTarget)
{
	UE_LOG(LogTemp, Warning, TEXT("NO ABILITY OVERRIDE DONE"));
	return false;
}

void UTBGameplayAbilityBase::AbilityTargetTile_Implementation(const TArray<AActor*>& SelectedTargets)
{
	//UE_LOG(LogTemp, Warning, TEXT("NO ABILITY TARGET IMPLEMENTED"));
	
	// Get abilitys owner and set in their Handler Component the new ability.
	if (GetOwningActorFromActorInfo()->FindComponentByClass<UTBAbilityHandlerComponent>())
	{
		TObjectPtr<UTBAbilityHandlerComponent> CharacterAbilityHandler = GetOwningActorFromActorInfo()->GetComponentByClass<UTBAbilityHandlerComponent>();

		if (IsValid(CharacterAbilityHandler))
		{
			AbilityTargets = SelectedTargets;
			UE_LOG(LogTemp, Warning, TEXT("AbilityHandler: %s"), *CharacterAbilityHandler->GetName());

			CharacterAbilityHandler->SetNewAbility(this);
		}
	}
}

bool UTBGameplayAbilityBase::ActivateAbility()
{
	return false;
}
