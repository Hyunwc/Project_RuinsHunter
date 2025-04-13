// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_EnemyStartUpData.h"
#include "AbilitySystem/HunterAbilitySystemComponent.h"
#include "AbilitySystem/Abilites/HunterEnemyGameplayAbility.h"

void UDataAsset_EnemyStartUpData::GiveToAbilitySystemComponent(UHunterAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	if (!EnemyCombatAbilities.IsEmpty())
	{
		for (const TSubclassOf<UHunterEnemyGameplayAbility>& AbilityClass : EnemyCombatAbilities)
		{
			if (!AbilityClass) continue;

			FGameplayAbilitySpec AbilitySpec(AbilityClass);
			AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
			AbilitySpec.Level = ApplyLevel;

			InASCToGive->GiveAbility(AbilitySpec);
		}
	}
}
