// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/HunterBaseAnimInstance.h"
#include "HunterFunctionLibrary.h"

bool UHunterBaseAnimInstance::DoesOwnerHaveTag(FGameplayTag TagToCheck) const
{
    if (APawn* OwningPawn = TryGetPawnOwner())
    {
        return UHunterFunctionLibrary::NativeDoesActorHaveTag(OwningPawn, TagToCheck);
    }

    return false;
}
