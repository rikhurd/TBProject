// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TBAbilityHandlerComponent.generated.h"

class ATBGameState;
class UTBGameplayAbilityBase;
class TBAbilityDataAsset;
class ATBCharacterBase;

/* UTBAbilityHandlerComponent is meant to be used to set new abilities and progress them in combat for all actors that are meant to be used in combat  */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class TBS_PROJECT_API UTBAbilityHandlerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTBAbilityHandlerComponent();

	/* Current ability to be handled */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Ability Handler")
	FGameplayAbilitySpecHandle CurrentAbilityHandle;

	/* Current ability to be handled */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Ability Handler")
	int32 CurrentAbilitySpeed;

	/** Set given ability to be used  */
	UFUNCTION(BlueprintCallable, Category = "Ability Handler")
	bool SetNewAbility(UTBGameplayAbilityBase* NewAbility, FGameplayAbilitySpecHandle NewAbilityHandle);

	/** Set given ability to be used  */
	UFUNCTION(BlueprintCallable, Category = "Ability Handler")
	bool RemoveAbilityFromUse();

	/** Progress ability's state.  */
	UFUNCTION(Category = "Ability Handler")
	void ProgressAbilityState();

private:
	UPROPERTY(VisibleDefaultsOnly, Category = "Ability Handler")
	class ATBGameState* GameState;

	UPROPERTY(VisibleDefaultsOnly)
	TObjectPtr<ATBCharacterBase> CastedOwner;

	FDelegateHandle CurrentAbilityDelegate;
};
