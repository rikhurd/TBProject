// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid/TBEntranceCollision.h"
#include "Grid/GridManager.h"
#include "Grid/TileBase.h"
#include "Components/BoxComponent.h"
#include "Math/Vector.h"
#include "Character/TBCharacterBase.h"
#include "GameFramework/GameState.h"

/*
As of currently entrance collision has a lot of placeholders. This is because of recent changes where I updated most of the project into C++ from Blueprints.
Because of this many things have changed and placeholders were made quickly so the projects works as intended before the changes.
For example: Player were linked into the grid where they could move and show off pathfinding.
*/

// Sets default values
ATBEntranceCollision::ATBEntranceCollision()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollisionComponent"));

	SetRootComponent(BoxCollision);

	BoxCollision->InitBoxExtent(FVector(100, 100, 100));

}

/*
GetOverlappingActors only works when in game and collision is not checked before game has started and collision is already inside the thing we want to check

Check collision WHEN:
	Player has first moved in the collision
		(OPTIONAL Boolean later) Player has pressed a key to enter into the grid's room. Player must make a conscious decision to enter themselves
			When player pressed a key in the collision. Check entrance tiles and player has to place its characters on the grids so the combat can start
*/
void ATBEntranceCollision::CheckCollision()
{
	EntranceTiles.Empty();
	TArray<AActor*> FoundTiles;

	BoxCollision->GetOverlappingActors(FoundTiles, ATileBase::StaticClass());
	
	/*
	Placeholder for checking if the tile is located inside the bound box
	Later this could be changed if the check for location is integrated into the GetOverlappingActors call.
	This would mean taking a branch of the Unreal Engine and modifying that which could take additional time and since this is also
	a portfolio project this could change how people could review and view this project.
	*/

	if (FoundTiles.IsEmpty()) UE_LOG(LogTemp, Error, TEXT("FoundTiles is empty"));

	for (AActor* tile : FoundTiles)
	{
		if (TileIsInsideXY(tile->GetActorLocation()))
		{
			ATileBase* CastedTile = Cast<ATileBase>(tile);
			EntranceTiles.Add(CastedTile);
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
bool ATBEntranceCollision::TileIsInsideXY(const FVector& In) const
{
	FVector ActorLocation = GetActorLocation();

	FVector BoxExtentMin = ActorLocation - (BoxCollision->GetScaledBoxExtent());
	FVector BoxExtentMax = ActorLocation + (BoxCollision->GetScaledBoxExtent());

	return ((In.X >= BoxExtentMin.X) && (In.X <= BoxExtentMax.X) && (In.Y >= BoxExtentMin.Y) && (In.Y <= BoxExtentMax.Y));
}

void ATBEntranceCollision::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->GetClass()->IsChildOf(ATBCharacterBase::StaticClass()))
	{
		CheckCollision();

		UE_LOG(LogTemp, Warning, TEXT("Actor overlapped entrance collision: %s"), *OtherActor->GetName());

		/* Execute Set Game State mode to call a delegate that fires off other calls that are needed for changing Game Sate Mode */
		AGameStateBase* GameState = GetWorld()->GetGameState();
		if (GameState->Implements<UTBGameStateChangeInterface>())
			ITBGameStateChangeInterface::Execute_SetGameStateMode(GameState, EGameStateMode::Combat);

		/*
		Placeholder. Currently update characters tile to the first tile in the array.
		This will be changed where characters would be able to placed on any tile.

		What this eventually will become is a call in player controller.
		That call takes in the entrance tiles and handles the pre placement of characters in the grid before the real combat begins.
			Call is done in controller because of multiplayer possibility later.
		*/
		ATBCharacterBase* CastedCharacter = Cast<ATBCharacterBase>(OtherActor);



		if (EntranceTiles.IsValidIndex(0))
		{
			CastedCharacter->SetActorLocation(FVector(EntranceTiles[0]->GetActorLocation().X,
																EntranceTiles[0]->GetActorLocation().Y,
																CastedCharacter->GetActorLocation().Z));

			CastedCharacter->UpdateCurrentTile(EntranceTiles[0]);
		}


	}
}

void ATBEntranceCollision::BeginPlay()
{
	Super::BeginPlay();

	/* Bind OnOverlapBegin on the component begin overlap.
	Doing this in BeginPlay is required since what we are trying to bind to is not ensured to be ready yet. */
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ATBEntranceCollision::OnOverlapBegin);
}
