// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/TBUWGameUI.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

// This was made to test C++ and BP connection in UI not sure if going to continue

void UTBUWGameUI::NativeConstruct()
{
	Super::NativeConstruct();

	if (AbilityButton)
	{
		AbilityButton->OnClicked.AddUniqueDynamic(this, &ThisClass::OnButtonClicked);
		
	}
}

void UTBUWGameUI::OnButtonClicked()
{
	OnClickedDelegate.Broadcast(this);
}