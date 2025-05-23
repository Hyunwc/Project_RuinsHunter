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
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_LightAttack_Hammer);
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_HeavyAttack_Hammer);
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Roll);

	/** Player Tags **/
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Equip_Hammer);
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Unequip_Hammer);
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Light_Hammer);
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Heavy_Hammer);
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_HitPause);
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Roll);

	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Hammer);

	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip_Hammer);
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Unequip_Hammer);
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_HitPause);

	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Status_JumpToFinisher);
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Status_Rolling);

	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_SetByCaller_AttackType_Light);
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_SetByCaller_AttackType_Heavy);

	/** Enemy Tags **/
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Ability_Melee);
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Ability_Ranged);

	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Weapon);

	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Status_Strafing);
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Status_UnderAttack);

	/** Shared Tags **/
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Ability_HitReact);
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Ability_Death);

	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Event_MeleeHit);
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Event_HitReact);

	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_SetByCaller_BaseDamage);

	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Status_Dead);
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Status_HitReact_Front);
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Status_HitReact_Left);
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Status_HitReact_Right);
	RUINSHUNTER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Status_HitReact_Back);
}
