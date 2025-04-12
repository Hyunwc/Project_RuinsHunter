// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameplayTagContainer.h"
#include "HunterTypes/HunterStructTypes.h"
#include "HunterAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class RUINSHUNTER_API UHunterAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void OnAbilityInputPressed(const FGameplayTag& InInputTag);
	void OnAbilityInputReleased(const FGameplayTag& InInputTag);

	UFUNCTION(BlueprintCallable, Category = "Hunter|Ability", meta = (ApplyLevel = "1"))
	void GrantPlayerWeaponAbilities(const TArray<FHunterPlayerAbilitySet>& InDefaultWeaponAbilities, int32 ApplyLevel,
		TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandles);
	
	// UPARAM -> �� �Ķ���ʹ� ��� �Ķ���Ͱ� �ƴ��� �˸�
	UFUNCTION(BlueprintCallable, Category = "Hunter|Ability")
	void RemoveGrantedPlayerWeaponAbilities(UPARAM(ref) TArray<FGameplayAbilitySpecHandle>& InSpecHandlesToRemove);
};
