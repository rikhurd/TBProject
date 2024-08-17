// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/TBCharacterBase.h"
#include "Grid/TileBase.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/Attributes/CharacterAttributeSet.h"
#include "AbilitySystem/Abilities/TBAbilityHandlerComponent.h"
#include "Grid/ActorTileAnchor.h"

ATBCharacterBase::ATBCharacterBase()
{
	AbilityHandlerComponent = CreateDefaultSubobject<UTBAbilityHandlerComponent>(TEXT("Ability Handler Component"));
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("Ability System Component"));

	TileAnchor = CreateDefaultSubobject<UActorTileAnchor>(TEXT("TileAnchor"));

	//Try GiveABility and get handle from it
	//FGameplayAbilitySpec AbilitySpec(AbilityCDO, AbilityToGrant.AbilityLevel);

	//AbilitySystemComponent->GiveAbility(AbilitySpec);
}

void ATBCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	check(AbilitySystemComponent);
	//if (IsValid(AbilitySystemComponent))
		// Get the UCharacterAttributeSet from our Ability System Component. The Ability System Component will create and register one if needed.
		AttributeSet = AbilitySystemComponent->GetSet<UCharacterAttributeSet>();
}

class UAbilitySystemComponent* ATBCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;

}

class UTBAbilityHandlerComponent* ATBCharacterBase::GetAbilityHandlerComponent() const
{
	return AbilityHandlerComponent;
}