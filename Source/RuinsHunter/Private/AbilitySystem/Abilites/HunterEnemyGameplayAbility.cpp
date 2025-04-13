// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilites/HunterEnemyGameplayAbility.h"
#include "Characters/HunterEnemyCharacter.h"

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
