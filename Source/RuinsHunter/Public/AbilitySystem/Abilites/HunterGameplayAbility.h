// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "HunterTypes/HunterEnumTypes.h"
#include "HunterGameplayAbility.generated.h"

class UPawnCombatComponent;
class UHunterAbilitySystemComponent;

UENUM(BlueprintType)
enum class EHunterAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};

/**
 * 
 */
UCLASS()
class RUINSHUNTER_API UHunterGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
protected:
	//~ Begin UGameplayAbility Interface.
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	//~ End UGameplayAbility Interface.
	// �Ҵ� ��å
	UPROPERTY(EditDefaultsOnly, Category = "HunterAbility")
	EHunterAbilityActivationPolicy AbilityActivationPolicy = EHunterAbilityActivationPolicy::OnTriggered;

	UFUNCTION(BlueprintPure, Category = "Huntrer|Ability")
	UPawnCombatComponent* GetPawnCombatComponentFromActionInfo() const;

	UFUNCTION(BlueprintPure, Category = "Huntrer|Ability")
	UHunterAbilitySystemComponent* GetHunterAbilitySystemComponent() const;

	FActiveGameplayEffectHandle NativeApplyEffectSpecHandleToTarget(AActor* TargetActor, const FGameplayEffectSpecHandle& InSpecHandle);

	UFUNCTION(BlueprintCallable, Category = "Hunter|Ability", meta = (DisplayName = "Apply Gameplay Effect Spec Handle To Target Actor", ExpandEnumAsExecs = "OutSuccessType"))
	FActiveGameplayEffectHandle BP_ApplyEffectSpecHandleToTarget(AActor* TargetActor, const FGameplayEffectSpecHandle& InSpecHandle, EHunterSuccessType& OutSuccessType);
};
