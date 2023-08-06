// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Math/IntPoint.h"

#include "TileBase.generated.h"

//Forward declaration
class AGridManager;
class UBoxComponent;

UCLASS(Blueprintable)
class TBS_PROJECT_API ATileBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATileBase();

	/** TileBase Index */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Pathfinding Variables")
		FIntPoint Index;

	/** Distance from the tile to the start tile */
	UPROPERTY(BlueprintReadOnly, Category = "Pathfinding Variables")
		double G;

	/** Distance from the tile to the target tile */
	UPROPERTY(BlueprintReadOnly, Category = "Pathfinding Variables")
		double H;

	/** G + H */
	UPROPERTY(BlueprintReadOnly, Category = "Pathfinding Variables")
		double F = G + H;

	/** Can any actor be on this tile */
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Pathfinding Variables")
		bool Walkable = true;

	/** Array of neighboring grid tiles */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Tile location variables")
		TArray<ATileBase*> Neighbors;

	/** Collision component. Shows grid size and location in the game and editor */
		UBoxComponent* BoxCollision;

	/** Please add a variable description */
		ATileBase* Connection;

	/* Currently done in child Blueprint
	UFUNCTION(BlueprintNativeEvent, Category = "Tile Selection Functions")
		void OnBeginCursorOver();

		void OnBeginCursorOver_Implementation();

	UFUNCTION(BlueprintNativeEvent, Category = "Tile Selection Functions")
		void OnEndCursorOver();

		void OnEndCursorOver_Implementation();*/

	/** Set distance from the tile to the start tile */
	UFUNCTION(BlueprintCallable, Category = "Set Variable Functions")
		void SetG(double InputG);

	/** Set distance from the tile to the end tile */
	UFUNCTION(BlueprintCallable, Category = "Set Variable Functions")
		void SetH(double InputH);

	/** Set connected tiles */
	UFUNCTION(BlueprintCallable, Category = "Set Variable Functions")
		void SetConnection(ATileBase* tileBase);

	/** Set neighbor tiles */
	UFUNCTION(BlueprintCallable, Category = "Set Variable Functions")
		void SetNeighbors(AGridManager* GridManager);

	/** Set neighbor tiles */
	UFUNCTION(BlueprintCallable, Category = "Set Variable Functions")
		float GetDistance(ATileBase* targetTile);

private:

	/** Array of neighboring tile directions */
		const TArray<FIntPoint> Dirs = {
		FIntPoint(0, 1), FIntPoint(-1, 0), FIntPoint(0, -1), FIntPoint(1, 0),
		FIntPoint(1, 1), FIntPoint(1, -1), FIntPoint(-1, -1), FIntPoint(-1, 1) };
};
