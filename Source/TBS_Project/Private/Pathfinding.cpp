// Fill out your copyright notice in the Description page of Project Settings.


#include "Pathfinding.h"
#include "TileBase.h"

/* Sets default values
UPathfinding::UPathfinding()
{

}*/

TArray<ATileBase*> UPathfinding::FindPath(ATileBase* startNode, ATileBase* targetNode)
{
	TArray<ATileBase*> toSearch;
	toSearch.Add(startNode);

	TArray<ATileBase*> processed;

	while (!toSearch.IsEmpty())
	{
		ATileBase* current = toSearch[0];
		for (auto node : toSearch)
		{
			if (node->F < current->F || node->F == current->F && node->H < current->H)
				current = node;
		}
			
			processed.Add(current);
			toSearch.Remove(current);
		

		if (current == targetNode)
		{
			ATileBase* currentPathTile = targetNode;
			TArray<ATileBase*> path;
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

