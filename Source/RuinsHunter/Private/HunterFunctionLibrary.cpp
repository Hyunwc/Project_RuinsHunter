// Fill out your copyright notice in the Description page of Project Settings.


#include "HunterFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/HunterAbilitySystemComponent.h"
#include "Interfaces/PawnCombatInterface.h"
#include "GenericTeamAgentInterface.h"
#include "Kismet/KismetMathLibrary.h"
#include "HunterGameplayTags.h"

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

UPawnCombatComponent* UHunterFunctionLibrary::NativeGetPawnCombatComponentFromActor(AActor* InActor)
{
    check(InActor);

    if (IPawnCombatInterface* PawnCombatInterface = Cast<IPawnCombatInterface>(InActor))
    {
        return PawnCombatInterface->GetPawnCombatComponent();
    }

    return nullptr;
}

UPawnCombatComponent* UHunterFunctionLibrary::BP_GetPawnCombatComponentFromActor(AActor* InActor, EHunterValidType& OutValidType)
{
    UPawnCombatComponent* CombatComponent = NativeGetPawnCombatComponentFromActor(InActor);

    OutValidType = CombatComponent ? EHunterValidType::Valid : EHunterValidType::Invalid;
    return CombatComponent;
}

bool UHunterFunctionLibrary::IsTargetPawnHostile(APawn* QueryPawn, APawn* TargetPawn)
{
    check(QueryPawn && TargetPawn);

    IGenericTeamAgentInterface* QueryTeamAgent = Cast<IGenericTeamAgentInterface>(QueryPawn->GetController());
    IGenericTeamAgentInterface* TargetTeamAgent = Cast<IGenericTeamAgentInterface>(TargetPawn->GetController());

    if (QueryTeamAgent && TargetTeamAgent)
    {
        return QueryTeamAgent->GetGenericTeamId() != TargetTeamAgent->GetGenericTeamId();
    }

    return false;
}

float UHunterFunctionLibrary::GetScalableFloatValueAtLevel(const FScalableFloat& InScalableFloat, float InLevel)
{
    return InScalableFloat.GetValueAtLevel(InLevel);
}

FGameplayTag UHunterFunctionLibrary::ComputeHitReactDirectionTag(AActor* InAttacker, AActor* InVictim, float& OutAngleDifference)
{
    check(InAttacker && InVictim);

    // 플레이어 타격 각도 계산
    const FVector VictimForward = InVictim->GetActorForwardVector();
    const FVector VictimToAttackerNormalized = (InAttacker->GetActorLocation() - InVictim->GetActorLocation()).GetSafeNormal();

    const float DotResult = FVector::DotProduct(VictimForward, VictimToAttackerNormalized);
    OutAngleDifference = UKismetMathLibrary::DegAcos(DotResult);

    const FVector CrossResult = FVector::CrossProduct(VictimForward, VictimToAttackerNormalized);

    if (CrossResult.Z < 0.f)
    {
        OutAngleDifference *= -1.f;
    }

    if (OutAngleDifference >= -45.f && OutAngleDifference <= 45.f)
    {
        return HunterGameplayTags::Shared_Status_HitReact_Front;
    }
    else if (OutAngleDifference < -45.f && OutAngleDifference >= 45.f)
    {
        return HunterGameplayTags::Shared_Status_HitReact_Left;
    }
    else if (OutAngleDifference < -135.f || OutAngleDifference > 135.f)
    {
        return HunterGameplayTags::Shared_Status_HitReact_Back;
    }
    else if (OutAngleDifference > 45.f && OutAngleDifference <= 135.f)
    {
        return HunterGameplayTags::Shared_Status_HitReact_Right;
    }

    return HunterGameplayTags::Shared_Status_HitReact_Front;
}
