// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/HunterCharacterAnimInstance.h"
#include "Characters/HunterBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UHunterCharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<AHunterBaseCharacter>(TryGetPawnOwner());

	if (OwningCharacter)
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}

void UHunterCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningCharacter || !OwningMovementComponent)
	{
		return;
	}

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();

	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;
}
