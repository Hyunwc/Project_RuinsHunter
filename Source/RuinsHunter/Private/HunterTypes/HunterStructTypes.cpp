// Fill out your copyright notice in the Description page of Project Settings.


#include "HunterTypes/HunterStructTypes.h"
#include "AbilitySystem/Abilites/HunterPlayerGameplayAbility.h"

bool FHunterPlayerAbilitySet::IsValid() const
{
    return InputTag.IsValid() && AbilityToGrant;
}
