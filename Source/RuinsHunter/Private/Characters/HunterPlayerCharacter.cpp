// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/HunterPlayerCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputSubsystems.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "Components/Input/HunterInputComponent.h"
#include "HunterGameplayTags.h"
#include "AbilitySystem/HunterAbilitySystemComponent.h"
#include "AbilitySystem/HunterAttributeSet.h"
#include "DataAssets/StartUpData/DataAsset_PlayerStartUpData.h"
#include "Components/Combat/PlayerCombatComponent.h"
#include "Components/UI/PlayerUIComponent.h"

#include "HunterDebugHelper.h"

AHunterPlayerCharacter::AHunterPlayerCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 200.f;
	CameraBoom->SocketOffset = FVector(0.f, 55.f, 65.f);
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	PlayerCombatComponent = CreateDefaultSubobject<UPlayerCombatComponent>(TEXT("PlayerCombatComponent"));
	PlayerUIComponent = CreateDefaultSubobject<UPlayerUIComponent>(TEXT("PlayerUIComponent"));
}

UPawnCombatComponent* AHunterPlayerCharacter::GetPawnCombatComponent() const
{
	return PlayerCombatComponent;
}

UPawnUIComponent* AHunterPlayerCharacter::GetPawnUIComponent() const
{
	return PlayerUIComponent;
}

UPlayerUIComponent* AHunterPlayerCharacter::GetPlayerUIComponent() const
{
	return PlayerUIComponent;
}

void AHunterPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (!CharacterStartUpData.IsNull())
	{
		if (UDataAsset_StartUpDataBase* LoadedData = CharacterStartUpData.LoadSynchronous())
		{
			LoadedData->GiveToAbilitySystemComponent(HunterAbilitySystemComponent);
		}
	}

	/*if (HunterAbilitySystemComponent && HunterAttributeSet)
	{
		const FString ASCText = FString::Printf(TEXT("Owner Actor : %s, AvatarActor : %s"),
			*HunterAbilitySystemComponent->GetOwnerActor()->GetActorLabel(),
			*HunterAbilitySystemComponent->GetAvatarActor()->GetActorLabel());
		Debug::Print(TEXT("Ability system Coponent Valid") + ASCText, FColor::Green);
		Debug::Print(TEXT("AttributeSet Valid") + ASCText, FColor::Green);
	}*/
}

void AHunterPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	checkf(InputConfigDataAsset, TEXT("Forgot to assign a valid data asset as input config"));
	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	check(Subsystem);

	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);

	UHunterInputComponent* HunterInputComponent = CastChecked<UHunterInputComponent>(PlayerInputComponent);

	// ��ǲ�� ���ε�
	HunterInputComponent->BindNativeInputAction(InputConfigDataAsset, HunterGameplayTags::InputTag_Move, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
	HunterInputComponent->BindNativeInputAction(InputConfigDataAsset, HunterGameplayTags::InputTag_Look, ETriggerEvent::Triggered, this, &ThisClass::Input_Look);

	HunterInputComponent->BindAbilityInputAction(InputConfigDataAsset, this, &ThisClass::Input_AbilityInputPressed, &ThisClass::Input_AbilityInputReleased);
}

void AHunterPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AHunterPlayerCharacter::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();
	const FRotator MovementRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);

	if (MovementVector.Y != 0.f)
	{
		const FVector ForwardDirection = MovementRotation.RotateVector(FVector::ForwardVector);

		AddMovementInput(ForwardDirection, MovementVector.Y);
	}

	if (MovementVector.X != 0.f)
	{
		const FVector RightDirection = MovementRotation.RotateVector(FVector::RightVector);

		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AHunterPlayerCharacter::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	if (LookAxisVector.X != 0.f)
	{
		AddControllerYawInput(LookAxisVector.X);
	}

	if (LookAxisVector.Y != 0.f)
	{
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AHunterPlayerCharacter::Input_AbilityInputPressed(FGameplayTag InInputTag)
{
	HunterAbilitySystemComponent->OnAbilityInputPressed(InInputTag);
}

void AHunterPlayerCharacter::Input_AbilityInputReleased(FGameplayTag InInputTag)
{
	HunterAbilitySystemComponent->OnAbilityInputReleased(InInputTag);
}
