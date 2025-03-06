// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayAbilitySpec.h" 

#include "TBAbilityDataAsset.generated.h"

UENUM(BlueprintType)
enum class EAbilityTargetSelectType : uint8
{
	Any,
	Sequence,
	Line,
	Cone,
	Character,
};

UCLASS(EditInlineNew, DefaultToInstanced, CollapseCategories, DisplayName = "Movement Variable Data")
class UAbilityVariableBaseData : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ActionSpeed = 1;
};

UCLASS(DisplayName = "Attack Variable Data")
class UAttackAbilityData : public UAbilityVariableBaseData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ActionDamage = 5;
};
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Instanced)
	class UAbilityVariableBaseData* AbilityVariableData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString AbilityDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EAbilityTargetSelectType AbilityTargetSelectType;
};
