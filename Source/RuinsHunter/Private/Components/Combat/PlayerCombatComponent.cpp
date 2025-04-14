// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/PlayerCombatComponent.h"
#include "Items/Weapons/HunterPlayerWeapon.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "HunterGameplayTags.h"

#include "HunterDebugHelper.h"

AHunterPlayerWeapon* UPlayerCombatComponent::GetPlayerCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
    return Cast<AHunterPlayerWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}

AHunterPlayerWeapon* UPlayerCombatComponent::GetPlayerCurrentEquippedWeapon() const
{
    return Cast<AHunterPlayerWeapon>(GetCharacterCurrentEquippedWeapon());
}

float UPlayerCombatComponent::GetPlayerCurrentEquippWeaponDamageAtLevel(float InLevel) const
{
    return GetPlayerCurrentEquippedWeapon()->PlayerWeaponData.WeaponBaseDamage.GetValueAtLevel(InLevel);
}

void UPlayerCombatComponent::OnHitTargetActor(AActor* HitActor)
{
    if (OverlappedActors.Contains(HitActor))
    {
        return;
    }

    OverlappedActors.AddUnique(HitActor);

    // 공격을 가한 폰 액터와 맞은 타겟
    FGameplayEventData Data;
    Data.Instigator = GetOwningPawn();
    Data.Target = HitActor;

    UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
        GetOwningPawn(),
        HunterGameplayTags::Shared_Event_MeleeHit,
        Data
    );
    //Debug::Print(GetOwningPawn()->GetActorNameOrLabel() + TEXT(" hit ") + HitActor->GetActorNameOrLabel(), FColor::Green);
}

void UPlayerCombatComponent::OnWeaponPulledFromTargetActor(AActor* InteractedActor)
{
    //Debug::Print(GetOwningPawn()->GetActorNameOrLabel() + TEXT(" 's weapon pulled from ") + InteractedActor->GetActorNameOrLabel(), FColor::Red);
}
