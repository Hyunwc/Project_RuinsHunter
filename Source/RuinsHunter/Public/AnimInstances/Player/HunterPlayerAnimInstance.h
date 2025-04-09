// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/HunterCharacterAnimInstance.h"
#include "HunterPlayerAnimInstance.generated.h"

class AHunterPlayerCharacter;
/**
 * 
 */
UCLASS()
class RUINSHUNTER_API UHunterPlayerAnimInstance : public UHunterCharacterAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;

	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds);

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData | Reference")
	AHunterPlayerCharacter* OwningPlayerCharacter;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData | LocomotionData")
	bool bShouldEnterRelaxState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData | LocomotionData")
	float EnterRelaxStateThreshold = 5.f; // idle에서 relax로 전환 시키기 위한 시간

	float IdleElpasedTime;
};
