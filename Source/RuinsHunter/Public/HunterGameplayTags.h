// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NativeGameplayTags.h"

namespace HunterGameplayTags
{
	/** Input Tags **/
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_EquipHammer);
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_UnequipHammer);

	/** Player Tags **/
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Equip_Hammer);
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Unequip_Hammer);

	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Hammer);

	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip_Hammer);
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Unequip_Hammer);

}
