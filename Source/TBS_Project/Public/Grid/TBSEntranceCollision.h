// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "TBSEntranceCollision.generated.h"

/**
 * 
 */
class UBoxComponent;
class AGridManager;
class ATileBase;

UCLASS()
class TBS_PROJECT_API ATBSEntranceCollision : public AActor
{
	GENERATED_BODY()

public:
		ATBSEntranceCollision();

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Components")
		UBoxComponent* BoxCollision;

	/** Please add a variable description 
	UPROPERTY(BlueprintReadOnly, EditInstanceOnly, Category = "Components")
		AGridManager* ConnectedGrid;
		*/

	/** Array of tiles that this entrance overlaps and are set as entrance on the grid */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Overlapping Tiles")
		TArray<AActor*> EntranceTiles;

	/* */
	UFUNCTION(CallInEditor, Category = "Overlap Collission")
		void CheckCollision();

	//~AActor interface
	//virtual void PostLoad() override;
	//virtual void BeginPlay() override;
	//~End of AActor interface

	bool TBSIsInsideXY(const FVector& In) const;
	
};
