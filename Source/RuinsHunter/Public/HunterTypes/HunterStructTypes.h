// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "HunterStructTypes.generated.h"

class UHunterPlayerLinkedAnimLayer;
class UHunterPlayerGameplayAbility;
class UInputMappingContext;

USTRUCT(BlueprintType)
struct FHunterPlayerAbilitySet
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UHunterPlayerGameplayAbility> AbilityToGrant;

	bool IsValid() const;
};

USTRUCT(BlueprintType)
struct FHunterPlayerWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UHunterPlayerLinkedAnimLayer> WeaponAnimLayerToLink;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* WeaponInputMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
	TArray<FHunterPlayerAbilitySet> DefaultWeaponAbilities;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FScalableFloat WeaponBaseDamage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftObjectPtr<UTexture2D> SoftWeaponIconTexture;
};

