// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/Player/HunterPlayerAnimInstance.h"
#include "Characters/HunterPlayerCharacter.h"

void UHunterPlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (OwningCharacter)
	{
		OwningPlayerCharacter = Cast<AHunterPlayerCharacter>(OwningCharacter);
	}
}

void UHunterPlayerAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (bHasAcceleration)
	{
		IdleElpasedTime = 0.f;
		bShouldEnterRelaxState = false;
	}
	else
	{
		IdleElpasedTime += DeltaSeconds;

		bShouldEnterRelaxState = (IdleElpasedTime >= EnterRelaxStateThreshold);
	}
}
