// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/TBGameplayAbilityBase.h"
#include "AbilitySystem/AttributeSets/TBAbilityAttributeSet.h"
#include "Character/TBCharacterBase.h"

bool UTBGameplayAbilityBase::AbilitySetup_Implementation(AActor* SelectedTarget)
{
	UE_LOG(LogTemp, Warning, TEXT("NO ABILITY OVERRIDE DONE"));
	return false;
}

void UTBGameplayAbilityBase::AbilityTargetTile_Implementation(const TArray<AActor*>& SelectedTargets, FGameplayAbilitySpecHandle AbilityHandle)
{
	//UE_LOG(LogTemp, Warning, TEXT("NO ABILITY TARGET IMPLEMENTED"));
	
	// Get abilitys owner and set in their Handler Component the new ability.
	if (TObjectPtr<ATBCharacterBase> OwningCharacter = Cast<ATBCharacterBase>(GetOwningActorFromActorInfo()))
	{
		AbilityTargets = SelectedTargets;
		UE_LOG(LogTemp, Warning, TEXT("AbilityHandler: %s"), AbilityHandle);

		OwningCharacter->SetNewAbility(this, AbilityHandle);
	}
}
