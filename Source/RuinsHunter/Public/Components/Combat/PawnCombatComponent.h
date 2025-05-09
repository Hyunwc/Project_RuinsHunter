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
	// �±�, ����� ����, ���Ⱑ ��ϵǾ�����?
	UFUNCTION(BlueprintCallable, Category = "Hunter|Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, AHunterWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false);

	UFUNCTION(BlueprintCallable, Category = "Hunter|Combat")
	AHunterWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

	// ���� �������� ���� �±�
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
	// Key : �±�, Value : ����� ����
	TMap<FGameplayTag, AHunterWeaponBase*> CharacterCarriedWeaponMap;
};
