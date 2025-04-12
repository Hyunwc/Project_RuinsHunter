// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/PlayerCombatComponent.h"
#include "Items/Weapons/HunterPlayerWeapon.h"

AHunterPlayerWeapon* UPlayerCombatComponent::GetPlayerCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
    return Cast<AHunterPlayerWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}
