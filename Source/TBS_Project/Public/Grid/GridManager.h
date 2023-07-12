// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/InstancedStaticMeshComponent.h" 
#include "GridManager.generated.h"

//Forward declaration
class ATileBase;

UCLASS()
class TBS_PROJECT_API AGridManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGridManager();

public:

	/** Spawns the grid to manager's location */
	UFUNCTION(BlueprintCallable)
		void SpawnGrid();

	/** Grid construction before spawning the grid */
	UFUNCTION(BlueprintCallable)
		void GridConstruction();

	/** Calculates grid tile location for spawning the grid */
	UFUNCTION(BlueprintCallable)
		FVector CalculateGridTileLocation(float IndexX, float IndexY);

	/** Calculates grid tile index */
	UFUNCTION(BlueprintCallable)
		FIntPoint CalculateGridTileIndex(float IndexX, float IndexY);

public:

	/** Basic mesh for walkable tiles */
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Grid components")
		TObjectPtr<UInstancedStaticMeshComponent> FloorMesh;

	/** Wall mesh is used later for creating impassable tiles on the grid not yet implemented */
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Grid components")
		TObjectPtr<UInstancedStaticMeshComponent> WallMesh;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Grid variables")
		FIntPoint GridTileCount = 10;
private:
	/** GridSnapValue is only used for placing the grid on the level. Snap comes from Unreal Engine's Grid Snap value in editor */
	UPROPERTY(EditDefaultsOnly, Category = "Grid variables")
		float GridSnapValue = 100;

	/* Subclass of the tile base that populates the grid */
	UPROPERTY(EditAnywhere, Category = "Grid components")
		TSubclassOf<ATileBase> TileBase;

public:
	/** Map of grid tiles. Map is because int point can be used to determine tile position in grid */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Grid variables")
		TMap<FIntPoint, ATileBase*> TileBaseMap;

	/** Gets tile position based on TileBaseMap's intpoint */
	UFUNCTION(BlueprintCallable)
		ATileBase* GetTileAtPosition (FIntPoint pos);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
