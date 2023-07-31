// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "TBSEntranceCollision.generated.h"

/**
 * 
 */
class UBoxComponent;
class AGridManager;

UCLASS()
class TBS_PROJECT_API ATBSEntranceCollision : public AActor
{
	GENERATED_BODY()

public:
		ATBSEntranceCollision();

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Components")
		UBoxComponent* BoxCollision;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, EditInstanceOnly, Category = "Components")
		AGridManager* ConnectedGrid;

};
