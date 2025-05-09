// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilites/HunterEnemyGameplayAbility.h"
#include "Characters/HunterEnemyCharacter.h"
#include "AbilitySystem/HunterAbilitySystemComponent.h"
#include "HunterGameplayTags.h"

AHunterEnemyCharacter* UHunterEnemyGameplayAbility::GetEnemyCharacterFromActorInfo()
{
    if (!CachedHunterEnemyCharacter.IsValid())
    {
        CachedHunterEnemyCharacter = Cast<AHunterEnemyCharacter>(CurrentActorInfo->AvatarActor);
    }
    return CachedHunterEnemyCharacter.IsValid() ? CachedHunterEnemyCharacter.Get() : nullptr;
}

UEnemyCombatComponent* UHunterEnemyGameplayAbility::GetEnemyCombatComponentFromActorInfo()
{
    return GetEnemyCharacterFromActorInfo()->GetEnemyCombatComponent();
}

FGameplayEffectSpecHandle UHunterEnemyGameplayAbility::MakeEnemyDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, const FScalableFloat& InDamageScalableFloat)
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
        InDamageScalableFloat.GetValueAtLevel(GetAbilityLevel())
    );

    return EffectSpecHandle;
}
