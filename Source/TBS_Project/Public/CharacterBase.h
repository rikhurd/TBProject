// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "AbilitySystemInterface.h"

#include "CharacterBase.generated.h"


//Forward declaration
class ATileBase;
/**
 * 
 */
UCLASS()
class TBS_PROJECT_API ACharacterBase : public APaperZDCharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
		class ATileBase* CurrentTile;

	/** Please add a function description  */
	UFUNCTION(BlueprintCallable)
		void UpdateCurrentTile(ATileBase* Tile);

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
		class UAbilitySystemComponent* AbilitySystemComponent;

	/** Returns our Ability System Component.  */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override
	{
		return AbilitySystemComponent;
	}
};
