// Fill out your copyright notice in the Description page of Project Settings.


#include "HunterGameplayTags.h"

namespace HunterGameplayTags
{
	/** Input Tags **/
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_EquipHammer, "InputTag.EquipHammer");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_UnequipHammer, "InputTag.UnequipHammer");

	/** Player Tags **/
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Hammer, "Player.Weapon.Hammer");
}
