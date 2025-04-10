// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "AbilitySystem/HunterAbilitySystemComponent.h"
#include "AbilitySystem/Abilites/HunterGameplayAbility.h"

// AbilitySystemComponent�� �ɷ� �ο�
void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UHunterAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	check(InASCToGive);

	GrantAbilities(ActivateOnGivenAbilities, InASCToGive, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InASCToGive, ApplyLevel);
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UHunterGameplayAbility>>& InAbilitiesToGive, UHunterAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty())
	{
		return;
	}

	for (const TSubclassOf<UHunterGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if (!Ability) continue;

		// Ability ������� GameplayAbilitySpec ����
		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		InASCToGive->GiveAbility(AbilitySpec);
	}
}
