// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "TBAbilityHandlerSystem.generated.h"

class UGameplayAbility;
class UGameplayEffect;

/**
 * 
 */
UCLASS()
class TBS_PROJECT_API UTBAbilityHandlerSystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:
	/*
	UTBAbilityHandlerSystem();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = "Lyra")
		void ApplyAbilityToAll(TSubclassOf<UGameplayAbility> Ability);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = "Lyra")
		void ApplyEffectToAll(TSubclassOf<UGameplayEffect> Effect);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = "Lyra")
		void RemoveAbilityFromAll(TSubclassOf<UGameplayAbility> Ability);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = "Lyra")
		void RemoveEffectFromAll(TSubclassOf<UGameplayEffect> Effect);

	/** Register an ASC with global system and apply any active global effects/abilities. 
	void RegisterASC(ULyraAbilitySystemComponent* ASC);

	/** Removes an ASC from the global system, along with any active global effects/abilities. 
	void UnregisterASC(ULyraAbilitySystemComponent* ASC);

private:
	UPROPERTY()
		TMap<TSubclassOf<UGameplayAbility>, FGlobalAppliedAbilityList> AppliedAbilities;

	UPROPERTY()
		TMap<TSubclassOf<UGameplayEffect>, FGlobalAppliedEffectList> AppliedEffects;

	UPROPERTY()
		TArray<TObjectPtr<ULyraAbilitySystemComponent>> RegisteredASCs; */
};
