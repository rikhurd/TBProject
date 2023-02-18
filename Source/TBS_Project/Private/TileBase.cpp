// Fill out your copyright notice in the Description page of Project Settings.


#include "TileBase.h"
#include "GridManager.h"

// Sets default values
ATileBase::ATileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	RootComponent = SceneComponent;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollisionComponent"));
	BoxCollision->SetBoxExtent(FVector(50, 50, 16));
	BoxCollision->SetCollisionProfileName("TileCollision");
	
	BoxCollision->SetupAttachment(RootComponent);
	BoxCollision->AddLocalOffset(FVector(0, 0, -15));

}

/*
void ATileBase::OnBeginCursorOver_Implementation()
{
}

void ATileBase::OnEndCursorOver_Implementation()
{
}
*/

void ATileBase::SetG(double InputG)
{
	G = InputG;
}

void ATileBase::SetH(double InputH)
{
	H = InputH;
}

void ATileBase::SetConnections(ATileBase* tileBase)
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

/* Called when the game starts or when spawned*/
void ATileBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

