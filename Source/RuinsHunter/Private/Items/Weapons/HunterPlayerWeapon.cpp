// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapons/HunterPlayerWeapon.h"

void AHunterPlayerWeapon::AssignGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InspecHandles)
{
	GrantedAbilitySpecHandles = InspecHandles;
}

TArray<FGameplayAbilitySpecHandle> AHunterPlayerWeapon::GetGrantedAbilitySpecHandles() const
{
	return GrantedAbilitySpecHandles;
}
