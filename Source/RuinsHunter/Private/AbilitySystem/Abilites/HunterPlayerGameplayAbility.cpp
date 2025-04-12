// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilites/HunterPlayerGameplayAbility.h"
#include "Characters/HunterPlayerCharacter.h"
#include "Controllers/HunterPlayerController.h"

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
