// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "TBAbilityHandlerComponent.generated.h"

class ATBGameState;
class UGameplayAbilityBase;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TBS_PROJECT_API UTBAbilityHandlerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTBAbilityHandlerComponent();

	/* Current ability to be handled */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Ability Handler")
		class UGameplayAbilityBase* CurrentAbility;

	/** Set given ability to be used  */
	UFUNCTION(BlueprintCallable, Category = "Ability Handler")
		void SetNewAbility(UGameplayAbilityBase* Ability);

	/** Progress ability's state.  */
	UFUNCTION(Category = "Ability Handler")
		void ProgressAbilityState();

	/*
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	*/
private:
	UPROPERTY(VisibleDefaultsOnly, Category = "Ability Handler")
		class ATBGameState* GameState;
};
