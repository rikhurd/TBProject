// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "CharacterAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class TBS_PROJECT_API UCharacterAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
protected:

    /** Health Attribute */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Attributes")
        FGameplayAttributeData Health;

    /** MovementRange Attribute */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Attributes")
        FGameplayAttributeData MovementRange;

public:

    //~ Helper functions for "Health" attributes */
    GAMEPLAYATTRIBUTE_VALUE_GETTER(Health);
    GAMEPLAYATTRIBUTE_VALUE_SETTER(Health);
    GAMEPLAYATTRIBUTE_VALUE_INITTER(Health);
    GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UCharacterAttributeSet, Health);

    //~ Helper functions for "MovementRange" attributes */
    GAMEPLAYATTRIBUTE_VALUE_GETTER(MovementRange);
    GAMEPLAYATTRIBUTE_VALUE_SETTER(MovementRange);
    GAMEPLAYATTRIBUTE_VALUE_INITTER(MovementRange);
    GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UCharacterAttributeSet, MovementRange);

};
