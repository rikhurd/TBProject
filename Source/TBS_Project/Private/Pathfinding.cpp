// Fill out your copyright notice in the Description page of Project Settings.


#include "Pathfinding.h"
#include "TileBase.h"

// Sets default values
APathfinding::APathfinding()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APathfinding::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APathfinding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APathfinding::FindPath(ATileBase* startNode, ATileBase* targetNode)
{
	TArray<ATileBase*> toSearch;
	toSearch.Add(startNode);

	TArray<ATileBase*> processed;

	while (!toSearch.IsEmpty())
	{
		ATileBase* current = toSearch[0];
		for (auto& node : toSearch)
		{
			if (node->F < current->F || node->F == current->F && node->H < current->H)
			{
				current = node;
			}

			processed.Add(current);
			toSearch.Remove(current);
		}

		//Process walkable and non-processed tiles here
		for (auto* neighbor : current->Neighbors)
		{

		}
	}
}

