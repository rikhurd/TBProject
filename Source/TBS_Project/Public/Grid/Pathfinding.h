// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Pathfinding.generated.h"

//Forward declaration
class ATileBase;
class ATBPlayerController;

UCLASS()
class TBS_PROJECT_API UPathfinding : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	//UPathfinding();

	UFUNCTION(BlueprintCallable, Category = "Find Path function")
	static TArray<ATileBase*> FindPath(ATileBase* startNode, ATileBase* targetNode);

	UFUNCTION(BlueprintCallable, Category = "Get Tile function")
	static void GetSelectedTile(APlayerController* PlayerController);
};
