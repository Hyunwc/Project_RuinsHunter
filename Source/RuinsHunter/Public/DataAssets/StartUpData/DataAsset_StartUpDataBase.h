// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class UHunterGameplayAbility;
class UHunterAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class RUINSHUNTER_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UHunterAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<UHunterGameplayAbility>> ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<UHunterGameplayAbility>> ReactiveAbilities;

	void GrantAbilities(const TArray<TSubclassOf<UHunterGameplayAbility>>& InAbilitiesToGive, UHunterAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
	
};
