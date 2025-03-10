// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "GridManager.generated.h"

//Forward declaration
class ATileBase;
class ATBSEntranceCollision;

UCLASS()
class TBS_PROJECT_API AGridManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGridManager();

	/** Map of grid tiles. Map is because int point can be used to determine tile position in grid */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Grid variables")
		TMap<FIntPoint, ATileBase*> TileBaseMap;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Grid variables")
		FIntPoint GridTileCount = { 3,3 };

	/** GridSnapValue is only used for placing the grid on the level. Name comes from Unreal Engine's Grid Snap value in editor
	This should be x + y of the box extent of the tile
	For example:
		50(x) + 50(y) = 100 value */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Grid variables")
		float GridSnapValue = 200;

private:

	/** Actor's scene component which is needed for things like position in the world */
	UPROPERTY()
		USceneComponent* SceneComponent;

	/*
	Subclass of the tile base that populates the grid
	This may change later to a static class when modifying TileBase class later
	Currently this is set in editor so we can use the Blueprint deprived class too.
	*/
	UPROPERTY(EditAnywhere, Category = "Grid variables")
		TSubclassOf<ATileBase> TileBase;

	/** Used to spawn the grid to manager's location */
	UFUNCTION(CallInEditor, BlueprintCallable, Category = "Grid spawner")
		void SpawnGrid();

	/** Calculates grid tile location for spawning the grid */
	UFUNCTION(BlueprintCallable)
		FVector CalculateGridTileLocation(float IndexX, float IndexY);

	/** Calculates grid tile index */
	UFUNCTION(BlueprintCallable)
		FIntPoint CalculateGridTileIndex(float IndexX, float IndexY);

public:

	/** Gets tile position based on TileBaseMap's intpoint */
	UFUNCTION(BlueprintCallable)
		ATileBase* GetTileAtPosition(FIntPoint pos);


};
