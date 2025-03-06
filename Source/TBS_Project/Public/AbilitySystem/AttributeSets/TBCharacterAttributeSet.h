// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "TBCharacterAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName);
/**
 * 
 */
UCLASS()
class TBS_PROJECT_API UTBCharacterAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:

    /** Health Attribute */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Attributes")
    FGameplayAttributeData Health;
    ATTRIBUTE_ACCESSORS(UTBCharacterAttributeSet, Health)
};
