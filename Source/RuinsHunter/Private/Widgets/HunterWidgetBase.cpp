// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/HunterWidgetBase.h"
#include "Interfaces/PawnUIInterface.h"

void UHunterWidgetBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	// 위젯을 소유중인 폰
	if (IPawnUIInterface* PawnUIInterface = Cast<IPawnUIInterface>(GetOwningPlayerPawn()))
	{
		if (UPlayerUIComponent* PlayerUIComponent = PawnUIInterface->GetPlayerUIComponent())
		{
			BP_OnOwningPlayerUIComponentInitialized(PlayerUIComponent);
		}
	}
}
