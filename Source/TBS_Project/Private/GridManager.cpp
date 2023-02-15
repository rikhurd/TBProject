// Fill out your copyright notice in the Description page of Project Settings.


#include "GridManager.h"

// Sets default values
AGridManager::AGridManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	FloorMesh = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("InstancedStaticMeshComponent"));
	FloorMesh->SetCollisionProfileName("NoCollision");
	RootComponent = FloorMesh;

}

void AGridManager::SpawnGrid()
{
	FVector GridTileLocation;

	for (int IndexY = 0; IndexY != GridTileCount.Y; ++IndexY)
	{
		for (int IndexX = 0; IndexX != GridTileCount.X; ++IndexX)
		{
			GridTileLocation = CalculateGridTileLocation(IndexX, IndexY);
			FloorMesh->AddInstance(FTransform(GridTileLocation), true);
			ATileBase* SpawnedTile = GetWorld()->SpawnActor<ATileBase>(TileBase, FTransform(GridTileLocation));
			TileBaseArray.Add(SpawnedTile);
		}
	}
}

FVector AGridManager::CalculateGridTileLocation(float IndexX, float IndexY)
{
	float X;
	float Y;

	X = IndexX - (GridTileCount.X / 2);
	Y = IndexY - (GridTileCount.Y / 2);

	FVector Location = FVector(X, Y, 0);
	Location *= GridSnapValue;

	Location = Location + (GridSnapValue * FVector(0.5, 0.5, 0));
	Location += GetActorLocation();

	return Location;
}

void AGridManager::GridConstruction()
{
	SpawnGrid();
}

// Called when the game starts or when spawned
void AGridManager::BeginPlay()
{
	Super::BeginPlay();

	GridConstruction();
	
}

// Called every frame
void AGridManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

