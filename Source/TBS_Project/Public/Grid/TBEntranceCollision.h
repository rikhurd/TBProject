// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameModes/TBGameStateChangeInterface.h"

#include "TBEntranceCollision.generated.h"

/**
 * 
 */
class UBoxComponent;
class AGridManager;
class ATileBase;

UCLASS()
class TBS_PROJECT_API ATBEntranceCollision : public AActor, public ITBGameStateChangeInterface
{
	GENERATED_BODY()

public:
	ATBEntranceCollision();

	/** Box collision component which checks for tiles and players. */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Components")
		UBoxComponent* BoxCollision;

	/** Array of tiles that this entrance overlaps and are set as entrance on the grid */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Overlapping Tiles")
		TArray<ATileBase*> EntranceTiles;

	/* Function to check the tiles inside the collision. Currently used in editor for testing. */
	UFUNCTION(CallInEditor, Category = "Overlapping Tiles")
		void CheckCollision();

	/* Check if given vector is inside of this actor's box collision. */
	bool TileIsInsideXY(const FVector& In) const;
	
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
