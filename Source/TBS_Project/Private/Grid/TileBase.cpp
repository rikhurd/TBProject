// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid/TileBase.h"
#include "Grid/GridManager.h"
#include "Components/BoxComponent.h"

// Sets default values
ATileBase::ATileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	SetRootComponent(SceneComponent);

	// Make box collision which handles the collision for mouse
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollisionComponent"));
	BoxCollision->SetBoxExtent(FVector(100, 100, 16));
	BoxCollision->SetCollisionProfileName("TileCollision");
	
	BoxCollision->SetupAttachment(RootComponent);
	BoxCollision->AddLocalOffset(FVector(0, 0, -15));

}

void ATileBase::SetG(double InputG)
{
	G = InputG;
	F = G + H;
}

void ATileBase::SetH(double InputH)
{
	H = InputH;
	F = G + H;
}

void ATileBase::SetConnection(ATileBase* tileBase)
{
	Connection = tileBase;
}

//Set tiles neighbors. Get TileBaseArray from the GridManager that calls it
void ATileBase::SetNeighbors(AGridManager* GridManager)
{
	for (auto& dir : Dirs)
	{
		if (ATileBase* tileToAdd = GridManager->GetTileAtPosition(dir + Index))
		{
			Neighbors.Add(tileToAdd);
		}
	}
}

float ATileBase::GetDistance(ATileBase* targetTile)
{
	FIntPoint dist = FIntPoint(abs(Index.X - targetTile->Index.X), abs(Index.Y - targetTile->Index.Y));

	int lowest = std::min(dist.X, dist.Y);
	int highest = std::max(dist.X, dist.Y);

	int horizontalMovesRequired = highest - lowest;

	return (lowest * 14 + horizontalMovesRequired * 10);
}