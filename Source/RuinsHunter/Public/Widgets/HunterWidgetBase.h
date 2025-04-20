// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HunterWidgetBase.generated.h"

class UPlayerUIComponent;
/**
 * 
 */
UCLASS()
class RUINSHUNTER_API UHunterWidgetBase : public UUserWidget
{
	GENERATED_BODY()

protected:
	// 위젯 생성 후 한번 호출됨
	virtual void NativeOnInitialized() override;
	
	// 블루프린트에서 구현할 함수
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Owning Player UI Component Initialized"))
	void BP_OnOwningPlayerUIComponentInitialized(UPlayerUIComponent* OwningPlayerUIComponent);
};
