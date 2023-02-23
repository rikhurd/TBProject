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

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Grid components")
		TObjectPtr<UInstancedStaticMeshComponent> FloorMesh;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Grid components")
		TObjectPtr<UInstancedStaticMeshComponent> WallMesh;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Grid variables")
		FIntPoint GridTileCount = 10;
private:
	/** Please add a variable description */
	UPROPERTY(EditDefaultsOnly, Category = "Grid variables")
		float GridSnapValue = 100;

	UPROPERTY(EditAnywhere, Category = "Grid components")
		TSubclassOf<ATileBase> TileBase;

public:
	/** Array of grid tiles */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Grid variables")
		TMap<FIntPoint, ATileBase*> TileBaseMap;

	/** Array of grid tiles */
	UFUNCTION(BlueprintCallable)
		ATileBase* GetTileAtPosition (FIntPoint pos);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
