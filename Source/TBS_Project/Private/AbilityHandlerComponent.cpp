// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityHandlerComponent.h"

// Sets default values for this component's properties
UAbilityHandlerComponent::UAbilityHandlerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// Add ref of an ability here that is going to be used by the character

	//Ref of the speed of the ability to use the countdown for the combat system to countdown
}


// Called when the game starts
void UAbilityHandlerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAbilityHandlerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

