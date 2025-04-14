// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilites/HunterPlayerGameplayAbility.h"
#include "Characters/HunterPlayerCharacter.h"
#include "Controllers/HunterPlayerController.h"
#include "AbilitySystem/HunterAbilitySystemComponent.h"
#include "HunterGameplayTags.h"

AHunterPlayerCharacter* UHunterPlayerGameplayAbility::GetPlayerCharacterFromActorInfo()
{
	if (!CachedHunterPlayerCharacter.IsValid())
	{
		CachedHunterPlayerCharacter = Cast<AHunterPlayerCharacter>(CurrentActorInfo->AvatarActor);
	}
	
	return CachedHunterPlayerCharacter.IsValid() ? CachedHunterPlayerCharacter.Get() : nullptr;
}

AHunterPlayerController* UHunterPlayerGameplayAbility::GetPlayerControllerFromActorInfo()
{
	if (!CachedHunterPlayerController.IsValid())
	{
		CachedHunterPlayerController = Cast<AHunterPlayerController>(CurrentActorInfo->PlayerController);
	}

	return CachedHunterPlayerController.IsValid() ? CachedHunterPlayerController.Get() : nullptr;
}

UPlayerCombatComponent* UHunterPlayerGameplayAbility::GetPlayerCombatComponentFromActorInfo()
{
	return GetPlayerCharacterFromActorInfo()->GetPlayerCombatComponent();
}

FGameplayEffectSpecHandle UHunterPlayerGameplayAbility::MakePlayerDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, float InWeaponBaseDamage, FGameplayTag InCurrentAttackTypeTag, int32 InUsedComboCount)
{
	check(EffectClass);

	FGameplayEffectContextHandle ContextHandle = GetHunterAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.SetAbility(this);
	ContextHandle.AddSourceObject(GetAvatarActorFromActorInfo());
	ContextHandle.AddInstigator(GetAvatarActorFromActorInfo(), GetAvatarActorFromActorInfo());

	FGameplayEffectSpecHandle EffectSpecHandle = GetHunterAbilitySystemComponent()->MakeOutgoingSpec(
		EffectClass,
		GetAbilityLevel(),
		ContextHandle
	);

	EffectSpecHandle.Data->SetSetByCallerMagnitude(
		HunterGameplayTags::Shared_SetByCaller_BaseDamage,
		InWeaponBaseDamage
	);

	if (InCurrentAttackTypeTag.IsValid())
	{
		EffectSpecHandle.Data->SetSetByCallerMagnitude(InCurrentAttackTypeTag, InUsedComboCount);
	}

	return EffectSpecHandle;
}
