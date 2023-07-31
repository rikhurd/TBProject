// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid/TBSEntranceCollision.h"
#include "Grid/GridManager.h"



// Sets default values
ATBSEntranceCollision::ATBSEntranceCollision()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollisionComponent"));

	RootComponent = BoxCollision;

	BoxCollision->SetBoxExtent(FVector(100, 100, 100));
	
}