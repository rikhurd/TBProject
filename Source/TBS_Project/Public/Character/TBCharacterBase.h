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

	UFUNCTION(BlueprintCallable, Category = "Game State Change Functions")
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	//~ End IAbilitySystemInterface

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
		class ATileBase* CurrentTile;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Ability Handler")
		class UTBAbilityHandlerComponent* AbilityHandlerComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Ability System")
		class UAbilitySystemComponent* AbilitySystemComponent;


protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		class UActorTileAnchor* TileAnchor;

	//UPROPERTY()
		const class UCharacterAttributeSet* AttributeSet;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};
