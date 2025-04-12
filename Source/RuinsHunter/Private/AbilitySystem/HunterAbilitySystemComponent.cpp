// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/HunterAbilitySystemComponent.h"

void UHunterAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	if (!InInputTag.IsValid())
	{
		return;
	}

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if(!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag)) continue;

		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UHunterAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
}
