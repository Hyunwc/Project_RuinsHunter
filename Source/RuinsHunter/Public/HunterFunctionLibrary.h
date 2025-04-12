// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HunterFunctionLibrary.generated.h"

class UHunterAbilitySystemComponent;

UENUM()
enum class EHunterConfirmType : uint8
{
	Yes,
	No
};
/**
 * 
 */
UCLASS()
class RUINSHUNTER_API UHunterFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static UHunterAbilitySystemComponent* NativeGetHunterASCFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "Hunter|FunctionLibrary")
	static void AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd);
	
	UFUNCTION(BlueprintCallable, Category = "Hunter|FunctionLibrary")
	static void RemoveGameplayFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove);

	static bool NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck);

	UFUNCTION(BlueprintCallable, Category = "Hunter|FunctionLibrary", meta = (DisplayName = "Does Actor Have Tag", ExpandEnumAsExecs = "OutConfirmType"))
	static void BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, EHunterConfirmType& OutConfirmType);
};
