// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// #include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TBUWGameUI.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTBAbilityOnClickedSignature, class UTBUWGameUI*, Button);
/**
 * This was made to test C++ and BP connection in UI not sure if going to continue
 */
UCLASS()

class TBS_PROJECT_API UTBUWGameUI : public UUserWidget
{
	GENERATED_BODY()

public:
	FTBAbilityOnClickedSignature OnClickedDelegate;

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* AbilityButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	class UTextBlock* AbilityButtonLabel;

	UFUNCTION()
	void OnButtonClicked();
};
