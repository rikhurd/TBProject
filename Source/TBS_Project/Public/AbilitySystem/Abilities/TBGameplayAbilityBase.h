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
	/* Target for the ability */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Ability Target")
	TArray<AActor*> AbilityTargets;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	 bool AbilitySetup(AActor* SelectedTarget);
	 bool AbilitySetup_Implementation(AActor* SelectedTarget);

	 void AbilityTargetTile_Implementation(TArray<AActor*>& SelectedTargets) override;
};
