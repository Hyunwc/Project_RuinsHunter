// Fill out your copyright notice in the Description page of Project Settings.


#include "HunterFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/HunterAbilitySystemComponent.h"

UHunterAbilitySystemComponent* UHunterFunctionLibrary::NativeGetHunterASCFromActor(AActor* InActor)
{
    check(InActor);

    return CastChecked<UHunterAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

void UHunterFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd)
{
    UHunterAbilitySystemComponent* ASC = NativeGetHunterASCFromActor(InActor);

    if (!ASC->HasMatchingGameplayTag(TagToAdd))
    {
        ASC->AddLooseGameplayTag(TagToAdd);
    }
}

void UHunterFunctionLibrary::RemoveGameplayFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove)
{
    UHunterAbilitySystemComponent* ASC = NativeGetHunterASCFromActor(InActor);

    if (!ASC->HasMatchingGameplayTag(TagToRemove))
    {
        ASC->RemoveLooseGameplayTag(TagToRemove);
    }
}

bool UHunterFunctionLibrary::NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck)
{
    UHunterAbilitySystemComponent* ASC = NativeGetHunterASCFromActor(InActor);

    return ASC->HasMatchingGameplayTag(TagToCheck);
}

void UHunterFunctionLibrary::BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, EHunterConfirmType& OutConfirmType)
{
    OutConfirmType = NativeDoesActorHaveTag(InActor, TagToCheck) ? EHunterConfirmType::Yes : EHunterConfirmType::No;
}
