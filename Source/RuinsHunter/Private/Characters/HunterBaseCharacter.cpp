// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/HunterBaseCharacter.h"
#include "AbilitySystem/HunterAbilitySystemComponent.h"
#include "AbilitySystem/HunterAttributeSet.h"

// Sets default values
AHunterBaseCharacter::AHunterBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	HunterAbilitySystemComponent = CreateDefaultSubobject<UHunterAbilitySystemComponent>(TEXT("HunterAbilitySystemComponent"));
	HunterAttributeSet = CreateDefaultSubobject<UHunterAttributeSet>(TEXT("HunterAttributeSet"));
}

UAbilitySystemComponent* AHunterBaseCharacter::GetAbilitySystemComponent() const
{
	return GetHunterAbilitySystemComponent();
}

UPawnCombatComponent* AHunterBaseCharacter::GetPawnCombatComponent() const
{
	return nullptr;
}

void AHunterBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (HunterAbilitySystemComponent)
	{
		// 어빌리티 초기화(소유자 액터, 아바타 액터)
		HunterAbilitySystemComponent->InitAbilityActorInfo(this, this);

		ensureMsgf(!CharacterStartUpData.IsNull(), TEXT("Forgot to assign start up data to %s"), *GetName());
	}
}

