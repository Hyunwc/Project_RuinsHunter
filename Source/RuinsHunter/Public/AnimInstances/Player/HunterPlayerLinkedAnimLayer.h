// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/HunterBaseAnimInstance.h"
#include "HunterPlayerLinkedAnimLayer.generated.h"

class UHunterPlayerAnimInstance;
/**
 * 
 */
UCLASS()
class RUINSHUNTER_API UHunterPlayerLinkedAnimLayer : public UHunterBaseAnimInstance
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
	UHunterPlayerAnimInstance* GetPlayerAnimInstance() const;
};
