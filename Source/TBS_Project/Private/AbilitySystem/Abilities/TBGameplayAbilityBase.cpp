// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/TBGameplayAbilityBase.h"
#include "AbilitySystem/Abilities/TBAbilityHandlerComponent.h"

bool UTBGameplayAbilityBase::AbilitySetup_Implementation(AActor* SelectedTarget)
{
	UE_LOG(LogTemp, Warning, TEXT("NO ABILITY OVERRIDE DONE"));
	return false;
}

void UTBGameplayAbilityBase::AbilityTargetTile_Implementation(AActor* SelectedTarget)
{
	//UE_LOG(LogTemp, Warning, TEXT("NO ABILITY TARGET IMPLEMENTED"));
	if (AbilitySetup(SelectedTarget))

		if (GetOwningActorFromActorInfo()->FindComponentByClass<UTBAbilityHandlerComponent>()) {

		
			TObjectPtr<UTBAbilityHandlerComponent> CharacterAbilityHandler = GetOwningActorFromActorInfo()->GetComponentByClass<UTBAbilityHandlerComponent>();

			if (IsValid(CharacterAbilityHandler))
			{
				//UE_LOG(LogTemp, Display, TEXT("Ability committed %s"), *this->GetName());
				CharacterAbilityHandler->SetNewAbility(this);
			}
		}
	// Get abilitys owner and set in their Handler Component the new ability.
}
