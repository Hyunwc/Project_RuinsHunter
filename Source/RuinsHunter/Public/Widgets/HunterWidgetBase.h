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
	// ���� ���� �� �ѹ� ȣ���
	virtual void NativeOnInitialized() override;
	
	// �������Ʈ���� ������ �Լ�
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Owning Player UI Component Initialized"))
	void BP_OnOwningPlayerUIComponentInitialized(UPlayerUIComponent* OwningPlayerUIComponent);
};
