// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

#include "TileBase.generated.h"


UCLASS(Blueprintable)
class TBS_PROJECT_API ATileBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATileBase();

	/** TileBase Index */
	UPROPERTY(BlueprintReadOnly, Category = "Pathfinding Variables")
		int Index;

	/** Distance from the tile to the start tile */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Pathfinding Variables")
		double G;

	/** Distance from the tile to the target tile */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Pathfinding Variables")
		double H;

	/** G + H */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Pathfinding Variables")
		double F = G + H;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
		TObjectPtr<UBoxComponent> BoxCollision;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
		TObjectPtr<USceneComponent> SceneComponent;

	/** Please add a variable description */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		ATileBase* Connection;

	/* Currently done in child Blueprint
	UFUNCTION(BlueprintNativeEvent, Category = "Tile Selection Functions")
		void OnBeginCursorOver();

		void OnBeginCursorOver_Implementation();

	UFUNCTION(BlueprintNativeEvent, Category = "Tile Selection Functions")
		void OnEndCursorOver();

		void OnEndCursorOver_Implementation();*/

	/** Set distance from the tile to the start tile */
	UFUNCTION(BlueprintCallable, Category = "Set Variable Functions")
		void SetG(double InputG);

	/** Set distance from the tile to the end tile */
	UFUNCTION(BlueprintCallable, Category = "Set Variable Functions")
		void SetH(double InputH);

	/** Set connected tiles */
	UFUNCTION(BlueprintCallable, Category = "Set Variable Functions")
		void SetConnections(ATileBase* tileBase);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
