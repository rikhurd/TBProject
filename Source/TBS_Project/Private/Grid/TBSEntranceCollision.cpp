// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid/TBSEntranceCollision.h"
#include "Grid/GridManager.h"
#include "Grid/TileBase.h"
#include "Components/BoxComponent.h"

// Sets default values
ATBSEntranceCollision::ATBSEntranceCollision()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollisionComponent"));

	SetRootComponent(BoxCollision);

	BoxCollision->SetBoxExtent(FVector(100, 100, 100));
	
}

/*
GetOverlappingActors only works when in game and collision is not checked before game has started and collision is already inside the thing we want to check

Check collision WHEN:
	Player has first moved in the collision
		(OPTIONAL Boolean later) Player has pressed a key to enter into the grid's room. Player must make a conscious decision to enter themselves
			When player pressed a key in the collision. Check entrance tiles and player has to place its characters on the grids so the combat can start
*/
void ATBSEntranceCollision::CheckCollision()
{
	EntranceTiles.Empty();
	TArray<AActor*> FoundTiles;

	BoxCollision->GetOverlappingActors(FoundTiles, ATileBase::StaticClass());
	
	/*
	Placeholder for checking if the tile is located inside the bound box
	Later this could be changed if the check for location is integrated into the GetOverlappingActors call.
	This would mean taking a branch of the Unreal Engine and modifying that which could take additional time and since this is also
	a portfolio project this could change how people could review this project.
	*/
	if (FoundTiles.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("FoundTiles is empty"));
	}
	for (AActor* tile : FoundTiles)
	{

		//FBox BoxBounds = BoxCollision->GetNavigationBounds();
		if (TBSIsInsideXY(tile->GetActorLocation()))
		{

			EntranceTiles.Add(tile);
		}
	}
}

/**
	 * Checks whether the given location is inside or on this box in the XY plane.
	 *
	 * @param In The location to test for inside the bounding volume.
	 * @return true if location is inside this box in the XY plane.
	 * 
	 */
bool ATBSEntranceCollision::TBSIsInsideXY(const FVector& In) const
{
	FVector BoxExtent = GetActorLocation();

	FVector BoxExtentMin = BoxExtent - (BoxCollision->GetScaledBoxExtent());
	FVector BoxExtentMax = BoxExtent + (BoxCollision->GetScaledBoxExtent());

	return ((In.X >= BoxExtentMin.X) && (In.X <= BoxExtentMax.X) && (In.Y >= BoxExtentMin.Y) && (In.Y <= BoxExtentMax.Y));
}


/*
void ATBSEntranceCollision::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp && OtherActor->GetClass()->IsChildOf(APawn::StaticClass()))
	{
		
	}
}
*/
