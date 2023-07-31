// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid/GridManager.h"
#include "Grid/TileBase.h"

// Sets default values
AGridManager::AGridManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	

}

void AGridManager::SpawnGrid()
{
	FVector GridTileLocation;

	TArray<AActor*> AttachedActors;
	GetAttachedActors(AttachedActors);
	
	/* Remove old attached actors in this Grid Manager */
	for (AActor* AttachedTileActor : AttachedActors)
		if (AttachedTileActor->IsA(ATileBase::StaticClass()))
			AttachedTileActor->Destroy();

	/* Spawns the grid and calculates needed positions */
	for (int IndexX = 0; IndexX != GridTileCount.X; ++IndexX)
		for (int IndexY = 0; IndexY != GridTileCount.Y; ++IndexY)
		{
			GridTileLocation = CalculateGridTileLocation(IndexX, IndexY);	
			if (ATileBase* SpawnedTile = GetWorld()->SpawnActorDeferred<ATileBase>(TileBase, FTransform(GridTileLocation)))
			{
				FIntPoint IndexPos = FIntPoint(IndexX, IndexY);
				SpawnedTile->Index = IndexPos;
				
				UGameplayStatics::FinishSpawningActor(SpawnedTile, FTransform(GridTileLocation));

				// Attach tile actor to the grid for group movement and deleting when spawning new grid.
				SpawnedTile->AttachToActor(this,FAttachmentTransformRules
					(EAttachmentRule::KeepRelative,EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative,false));

				TileBaseMap.Add(IndexPos,SpawnedTile);
			}
		}

	//Sets tile neighbors based on intpoint values
	for (auto& tile : TileBaseMap)
		tile.Value->SetNeighbors(this);
}

FVector AGridManager::CalculateGridTileLocation(float IndexX, float IndexY)
{
	FVector Location = FVector(IndexX, IndexY, 0);
	Location *= GridSnapValue;

	Location = Location + (GridSnapValue * FVector(0.5, 0.5, 0));

	return Location;
}

FIntPoint AGridManager::CalculateGridTileIndex(float IndexX, float IndexY)
{
	FIntPoint TileIndex;
	int Index;

	Index = IndexY * GridTileCount.X;
	Index += IndexX;

	TileIndex.X = Index % GridTileCount.Y;
	TileIndex.Y = Index / GridTileCount.Y;

	return TileIndex;
}

ATileBase* AGridManager::GetTileAtPosition(FIntPoint pos)
{
	auto tile = TileBaseMap.FindRef(pos);

	return tile;
}
