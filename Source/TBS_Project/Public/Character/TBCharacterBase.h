// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameModes/TBGameStateChangeInterface.h"

#include "TBCharacterBase.generated.h"


//Forward declaration
class ATileBase;
class UTBAbilityHandlerComponent;
class UActorTileAnchor;

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

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Ability Handler")
	TObjectPtr<UTBAbilityHandlerComponent> AbilityHandlerComponent;

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

protected:

	//UPROPERTY()
		const class UCharacterAttributeSet* AttributeSet;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	/** Current Tile this character is on */
	UPROPERTY(EditDefaultsOnly, BlueprintGetter = GetCurrentTile, BlueprintSetter = SetCurrentTile)
	TObjectPtr<ATileBase> CurrentTile;
};
