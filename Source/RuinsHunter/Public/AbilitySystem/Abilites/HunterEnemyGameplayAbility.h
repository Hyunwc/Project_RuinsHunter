// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilites/HunterGameplayAbility.h"
#include "HunterEnemyGameplayAbility.generated.h"

class AHunterEnemyCharacter;
class UEnemyCombatComponent;

/**
 * 
 */
UCLASS()
class RUINSHUNTER_API UHunterEnemyGameplayAbility : public UHunterGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Hunter|Ability")
	AHunterEnemyCharacter* GetEnemyCharacterFromActorInfo();
	
	UFUNCTION(BlueprintPure, Category = "Hunter|Ability")
	UEnemyCombatComponent* GetEnemyCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<AHunterEnemyCharacter> CachedHunterEnemyCharacter;
};
