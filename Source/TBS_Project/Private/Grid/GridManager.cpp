// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid/GridManager.h"
#include "Grid/TileBase.h"

// Sets default values
AGridManager::AGridManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	FloorMesh = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("InstancedStaticMeshComponent"));
	FloorMesh->SetCollisionProfileName("NoCollision");
	RootComponent = FloorMesh;
}

void AGridManager::SpawnGrid()
{
	FVector GridTileLocation;

	for (int IndexX = 0; IndexX != GridTileCount.X; ++IndexX)
	{
		for (int IndexY = 0; IndexY != GridTileCount.Y; ++IndexY)
		{
			GridTileLocation = CalculateGridTileLocation(IndexX, IndexY);	
			if (ATileBase* SpawnedTile = GetWorld()->SpawnActorDeferred<ATileBase>(TileBase, FTransform(GridTileLocation)))
			{
				FIntPoint IndexPos = FIntPoint(IndexX, IndexY);
				SpawnedTile->Index = IndexPos;

				UGameplayStatics::FinishSpawningActor(SpawnedTile, FTransform(GridTileLocation));

				TileBaseMap.Add(IndexPos,SpawnedTile);
			}
		}
	}
}

FVector AGridManager::CalculateGridTileLocation(float IndexX, float IndexY)
{
	FVector Location = FVector(IndexX, IndexY, 0);
	Location *= GridSnapValue;

	Location = Location + (GridSnapValue * FVector(0.5, 0.5, 0));
	Location += GetActorLocation();

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

// Called when the game starts or when spawned
void AGridManager::BeginPlay()
{
	Super::BeginPlay();

	SpawnGrid();

	//Sets tile neighbors based on intpoint values
	for (auto& tile : TileBaseMap)
	{
		tile.Value->SetNeighbors(this);
	}
}

ATileBase* AGridManager::GetTileAtPosition(FIntPoint pos)
{
	auto tile = TileBaseMap.FindRef(pos);

	return tile;
}

void AGridManager::SpawnPreviewGrid()
{
	// Clear instances before spawning new ones
	FloorMesh->ClearInstances();

	for (int IndexX = 0; IndexX != GridTileCount.X; ++IndexX)
	{
		for (int IndexY = 0; IndexY != GridTileCount.Y; ++IndexY)
		{
			FloorMesh->AddInstance(FTransform(CalculateGridTileLocation(IndexX, IndexY)), true);
		}
	}
}

void AGridManager::DestroyPreviewGrid()
{
	FloorMesh->ClearInstances();
}
