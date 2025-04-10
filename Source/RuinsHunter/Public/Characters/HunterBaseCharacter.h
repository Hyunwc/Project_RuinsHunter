// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "HunterBaseCharacter.generated.h"

class UHunterAbilitySystemComponent;
class UHunterAttributeSet;
class UDataAsset_StartUpDataBase;

UCLASS()
class RUINSHUNTER_API AHunterBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHunterBaseCharacter();

	//~ Begin IAbilitySystemInterface Interface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface Interface
protected:
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UHunterAbilitySystemComponent* HunterAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UHunterAttributeSet* HunterAttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData")
	TSoftObjectPtr<UDataAsset_StartUpDataBase> CharacterStartUpData;

public:
	FORCEINLINE UHunterAbilitySystemComponent* GetHunterAbilitySystemComponent() const { return HunterAbilitySystemComponent; }
	
	FORCEINLINE UHunterAttributeSet* GetHunterAttributeSet() const { return HunterAttributeSet; }

};
