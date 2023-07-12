// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/TBCharacterBase.h"
#include "Grid/TileBase.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/Attributes/CharacterAttributeSet.h"
#include "AbilitySystem/Abilities/TBAbilityHandlerComponent.h"

ATBCharacterBase::ATBCharacterBase()
{
	AbilityHandlerComponent = CreateDefaultSubobject<UAbilityHandlerComponent>(TEXT("Ability Handler Component"));
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("Ability System Component"));

}

void ATBCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(AbilitySystemComponent))
	{
		// Get the UCharacterAttributeSet from our Ability System Component. The Ability System Component will create and register one if needed.
		AttributeSet = AbilitySystemComponent->GetSet<UCharacterAttributeSet>();
	}
}

/* Change this later to be made from ability Move */
void ATBCharacterBase::UpdateCurrentTile(ATileBase* Tile)
{
	CurrentTile = Tile;
}

