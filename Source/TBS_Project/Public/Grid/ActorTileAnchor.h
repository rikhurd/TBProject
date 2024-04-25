// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActorTileAnchor.generated.h"

class ATileBase;

// This component is added to every actor that occupies a tile in the grid.

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TBS_PROJECT_API UActorTileAnchor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActorTileAnchor();

	/** This variable has reference into the actor that occupies this tile */
	UPROPERTY(BlueprintReadOnly, Category = "Tile Anchor Variables")
	TWeakObjectPtr<ATileBase> AnchorTile;

	TWeakObjectPtr<ATileBase> GetAnchorTile() const { return AnchorTile; }

	/* Removes earlier reference of anchor actor and sets a new reference to it */
	void SetAnchorTile(ATileBase* NewTileActor);
	void RemoveTileOccupier();
		
};
