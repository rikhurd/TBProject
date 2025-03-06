// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameModes/TBGameStateChangeInterface.h"

#include "TBCharacterBase.generated.h"


//Forward declaration
class ATileBase;
class UTBAbilityAttributeSet;
class ATBGameState;
class UTBGameplayAbilityBase;
class TBAbilityDataAsset;

/**
 * 
 */
UCLASS()
class TBS_PROJECT_API ATBCharacterBase : public ACharacter, public IAbilitySystemInterface, public ITBGameStateChangeInterface
{
	GENERATED_BODY()
	
public:
	ATBCharacterBase();

	//~ Begin IAbilitySystemInterface

	UFUNCTION(BlueprintCallable, Category = "Ability System")
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	//~ End IAbilitySystemInterface

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Ability System")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	//~ These two overttide Blueprint Get and Set

	UFUNCTION(BlueprintGetter)
	ATileBase* GetCurrentTile() const
	{
		return CurrentTile;
	};

	UFUNCTION(BlueprintSetter)
	void SetCurrentTile(ATileBase* NewTile)
	{
		CurrentTile = NewTile;
	};

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

	/* Adds Ability Attribute set into the character's ability system component */
	UFUNCTION(BlueprintCallable, Category = "Ability AttributeSet")
	bool AddAbilityAttributeSet(UTBAbilityAttributeSet* NewAbilityAttributeSet);

	/* Remove Ability Attribute set from the character's ability system component */
	UFUNCTION(BlueprintCallable, Category = "Ability AttributeSet")
	bool RemoveAbilityAttributeSet(UTBAbilityAttributeSet* OldAbilityAttributeSet);

protected:

	//UPROPERTY()
		const class UTBCharacterAttributeSet* CharacterAttributeSet;

		const class UTBAbilityAttributeSet* CurrentAbilityAttributeSet;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	/** Current Tile this character is on */
	UPROPERTY(EditDefaultsOnly, BlueprintGetter = GetCurrentTile, BlueprintSetter = SetCurrentTile)
	TObjectPtr<ATileBase> CurrentTile;

	UPROPERTY(VisibleDefaultsOnly, Category = "Ability Handler")
	class ATBGameState* GameState;
};
