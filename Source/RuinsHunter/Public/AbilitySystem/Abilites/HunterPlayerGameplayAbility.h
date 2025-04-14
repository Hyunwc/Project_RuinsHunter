// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilites/HunterGameplayAbility.h"
#include "HunterPlayerGameplayAbility.generated.h"


class AHunterPlayerCharacter;
class AHunterPlayerController;

/**
 * 
 */
UCLASS()
class RUINSHUNTER_API UHunterPlayerGameplayAbility : public UHunterGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Huntrer|Ability")
	AHunterPlayerCharacter* GetPlayerCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Huntrer|Ability")
	AHunterPlayerController* GetPlayerControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Huntrer|Ability")
	UPlayerCombatComponent* GetPlayerCombatComponentFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Huntrer|Ability")
	FGameplayEffectSpecHandle MakePlayerDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass,
		float InWeaponBaseDamage,
		FGameplayTag InCurrentAttackTypeTag,
		int32 InUsedComboCount);

private:
	TWeakObjectPtr<AHunterPlayerCharacter> CachedHunterPlayerCharacter;
	TWeakObjectPtr<AHunterPlayerController> CachedHunterPlayerController;
};
