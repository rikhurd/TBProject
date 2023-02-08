// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <TileBase.h>

#include "GridManager.generated.h"


UCLASS()
class TBS_PROJECT_API AGridManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGridManager();

public:

	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
		void SpawnGrid();

	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
		void GridConstruction();

public:
	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Default")
		TObjectPtr<UInstancedStaticMeshComponent> FloorMesh;

	/** Please add a variable description 
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
		TObjectPtr<ABP_GameMode_C> GameModeRef;*/

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
		FIntPoint GridTileCount = 10;
private:
	/** Please add a variable description */
	UPROPERTY(EditDefaultsOnly, Category = "Default")
		double GridSnapValue;

public:
	/** Array of grid tiles */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
		TArray<ATileBase*> TileCollisionArray;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
