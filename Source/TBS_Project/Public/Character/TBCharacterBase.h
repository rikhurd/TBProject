// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameModes/TBGameStateChangeInterface.h"

#include "TBCharacterBase.generated.h"


//Forward declaration
class ATileBase;
class UAbilityHandlerComponent;

/**
 * 
 */
UCLASS()
class TBS_PROJECT_API ATBCharacterBase : public ACharacter, public IAbilitySystemInterface, public ITBGameStateChangeInterface
{
	GENERATED_BODY()
	
public:
	ATBCharacterBase();

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
		class ATileBase* CurrentTile;

	/** Please add a function description  */
	UFUNCTION(BlueprintCallable)
		void UpdateCurrentTile(ATileBase* Tile);

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Ability Handler")
		class UAbilityHandlerComponent* AbilityHandlerComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Ability System")
		class UAbilitySystemComponent* AbilitySystemComponent;

	/** Returns our Ability System Component.  */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override
	{
		return AbilitySystemComponent;
	}

protected:

	UPROPERTY()
		const class UCharacterAttributeSet* AttributeSet;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};
