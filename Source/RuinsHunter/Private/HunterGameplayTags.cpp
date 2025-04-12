// Fill out your copyright notice in the Description page of Project Settings.


#include "HunterGameplayTags.h"

namespace HunterGameplayTags
{
	/** Input Tags **/
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_EquipHammer, "InputTag.EquipHammer");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_UnequipHammer, "InputTag.UnequipHammer");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_LightAttack_Hammer, "InputTag.LightAttack.Hammer");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_HeavyAttack_Hammer, "InputTag.HeavyAttack.Hammer");

	/** Player Tags **/
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Equip_Hammer, "Player.Ability.Equip.Hammer");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Unequip_Hammer, "Player.Ability.Unequip.Hammer");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Light_Hammer, "Player.Ability.Attack.Light.Hammer");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Heavy_Hammer, "Player.Ability.Attack.Heavy.Hammer");

	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Hammer, "Player.Weapon.Hammer");

	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Equip_Hammer, "Player.Event.Equip.Hammer");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Unequip_Hammer, "Player.Event.Unequip.Hammer");

	UE_DEFINE_GAMEPLAY_TAG(Player_Status_JumpToFinisher, "Player.Status.JumpToFinisher");
}
