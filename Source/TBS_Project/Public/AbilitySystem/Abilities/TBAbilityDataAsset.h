// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayAbilitySpec.h" 

#include "TBAbilityDataAsset.generated.h"


/**
 * 
 */
UCLASS(BlueprintType)
class TBS_PROJECT_API UTBAbilityDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName AbilityName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UTexture2D> AbilityThumbnail;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftClassPtr<UGameplayAbility> AbilityClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString AbilityDescription;
};