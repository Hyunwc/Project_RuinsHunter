// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/Player/HunterPlayerLinkedAnimLayer.h"
#include "AnimInstances/Player/HunterPlayerAnimInstance.h"

UHunterPlayerAnimInstance* UHunterPlayerLinkedAnimLayer::GetPlayerAnimInstance() const
{
    return Cast<UHunterPlayerAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
