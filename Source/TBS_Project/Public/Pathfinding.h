// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pathfinding.generated.h"

//Forward declaration
class ATileBase;

UCLASS()
class TBS_PROJECT_API APathfinding : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APathfinding();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	static void FindPath(ATileBase* startNode, ATileBase* targetNode);

};
