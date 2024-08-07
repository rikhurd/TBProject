// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid/Pathfinding.h"
#include "Grid/TileBase.h"
#include "Player/TBPlayerController.h"

/* Sets default values
UPathfinding::UPathfinding()
{

}*/

TArray<ATileBase*> UPathfinding::FindPath(ATileBase* startNode, ATileBase* targetNode)
{
	TArray<TObjectPtr<ATileBase>> toSearch;
	toSearch.Add(startNode);

	TArray<TObjectPtr<ATileBase>> processed;

	while (!toSearch.IsEmpty())
	{
		/*
		THIS MAY LATER BE DELETED because of movement changes on players. However could still be useful for queue player movement or enemy AI calculation of player location.
		OPTIMIZE THIS
		Currently finding best F cost node is the best way to optimize pathfinding
		Even though it is probably not necessary for project this big,
		but would look better if project is sent a part of portfolio and also for learning optimization
		
		Could be replaced with a Heap

		*/
		TObjectPtr<ATileBase> current = toSearch[0];
		for (ATileBase* node : toSearch)
		{
			if (node->F < current->F || node->F == current->F && node->H < current->H)
				current = node;
		}
		
			processed.Add(current);
			toSearch.Remove(current);
		

		if (current == targetNode)
		{
			TObjectPtr<ATileBase> currentPathTile = targetNode;
			TArray<TObjectPtr<ATileBase>> path;
			int count = 100;
			while (currentPathTile != startNode)
			{
				path.Add(currentPathTile);
				currentPathTile = currentPathTile->Connection;
				count--;
				if (count < 0) throw;
			}
			return path;
		}

		//Process walkable and non-processed tiles here
		for (auto* neighbor : current->Neighbors)
		{
			if ( neighbor->Walkable == true && !processed.Contains(neighbor))
			{
				bool inSearch = toSearch.Contains(neighbor);

				float costToNeighbor = current->G + current->GetDistance(neighbor);

				if (!inSearch || costToNeighbor < neighbor->G)
				{
					neighbor->SetG(costToNeighbor);

					//TODO: Check this functions necessity
					neighbor->SetConnection(current);

					if (!inSearch)
					{
						neighbor->SetH(neighbor->GetDistance(targetNode));
						toSearch.Add(neighbor);
					}
				}
			}
		}
	}
	return TArray<ATileBase*>();
}


// Set boolean to controller so controller changes to a state where u can select a tile. ALSO maybe add ability handler as a parameter. DO U NEED WHOLE PATH IN THE ABILITY? OR SAVE IT IN CONTROLLER
void UPathfinding::GetSelectedTile(APlayerController* PlayerController)
{
	if (ATBPlayerController* MyPlayerController = Cast<ATBPlayerController>(PlayerController)) {
		MyPlayerController->SelectTileForAbility = true;
	}
}