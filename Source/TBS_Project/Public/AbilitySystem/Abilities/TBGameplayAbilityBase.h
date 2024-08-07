// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AbilitySystem/TBAbilityInterface.h"
#include "TBGameplayAbilityBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TBS_PROJECT_API UTBGameplayAbilityBase : public UGameplayAbility, public ITBAbilityInterface
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	 bool AbilitySetup();
	 bool AbilitySetup_Implementation();

	 void AbilityTargetTile_Implementation(AActor* SelectedTarget) override;
};
