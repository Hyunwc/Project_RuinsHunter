// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtensionComponentBase.h"
#include "GameplayTagContainer.h"
#include "PawnCombatComponent.generated.h"

class AHunterWeaponBase;

UENUM(BlueprintType)
enum class EToggleDamageType : uint8
{
	CurrentEquippedWeapon,
	LeftHand,
	RightHand
};

/**
 * 
 */
UCLASS()
class RUINSHUNTER_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()
	
public:
	// 태그, 등록할 무기, 무기가 등록되었는지?
	UFUNCTION(BlueprintCallable, Category = "Hunter|Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, AHunterWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false);

	UFUNCTION(BlueprintCallable, Category = "Hunter|Combat")
	AHunterWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

	// 현재 장착중인 무기 태그
	UPROPERTY(BlueprintReadWrite, Category = "Hunter|Combat")
	FGameplayTag CurrentEquippedWeaponTag;

	UFUNCTION(BlueprintCallable, Category = "Hunter|Combat")
	AHunterWeaponBase* GetCharacterCurrentEquippedWeapon() const;

	UFUNCTION(BlueprintCallable, Category = "Hunter|Combat")
	void ToggleWeaponCollision(bool bShouldEnable, EToggleDamageType ToggleDamageType = EToggleDamageType::CurrentEquippedWeapon);

	virtual void OnHitTargetActor(AActor* HitActor);
	virtual void OnWeaponPulledFromTargetActor(AActor* InteractedActor);
	
protected:
	TArray<AActor*> OverlappedActors;

private:
	// Key : 태그, Value : 등록할 무기
	TMap<FGameplayTag, AHunterWeaponBase*> CharacterCarriedWeaponMap;
};
