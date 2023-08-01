// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid/TBSEntranceCollision.h"
#include "Grid/GridManager.h"



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
void ATBSEntranceCollision::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp && OtherActor->GetClass()->IsChildOf(APawn::StaticClass()))
	{
		
	}
}
*/