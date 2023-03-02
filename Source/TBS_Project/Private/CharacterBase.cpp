// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBase.h"
#include "TileBase.h"
#include "AbilitySystemComponent.h"
#include "CharacterAttributeSet.h"

ACharacterBase::ACharacterBase()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("Ability System Component"));
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(AbilitySystemComponent))
	{
		// Get the UCharacterAttributeSet from our Ability System Component. The Ability System Component will create and register one if needed.
		AttributeSet = AbilitySystemComponent->GetSet<UCharacterAttributeSet>();
	}
}

void ACharacterBase::UpdateCurrentTile(ATileBase* Tile)
{
	CurrentTile = Tile;
}

