// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AbilitySystem/Abilities/TBGameplayAbilityBase.h"

#include "TBAbilityDataAsset.generated.h"


/**
 * 
 */

USTRUCT()
struct FAbilityInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FString AssetName;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UTexture2D> AssetThumbnail;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UTBGameplayAbilityBase> AssetAbility;
};

UCLASS()
class TBS_PROJECT_API UTBAbilityDataAsset : public UDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<FAbilityInfo> AssetItems;
};
