// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/HunterAIController.h"
#include "Navigation/CrowdFollowingComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "HunterDebugHelper.h"

AHunterAIController::AHunterAIController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>("PathFollowingComponent"))
{
	AISenseConfig_Sight = CreateDefaultSubobject<UAISenseConfig_Sight>("EnemySenseConfig_Sight");
	AISenseConfig_Sight->DetectionByAffiliation.bDetectEnemies = true; // ���� ����
	AISenseConfig_Sight->DetectionByAffiliation.bDetectFriendlies = false; // �Ʊ� ����
	AISenseConfig_Sight->DetectionByAffiliation.bDetectNeutrals = false; // �߸�
	AISenseConfig_Sight->SightRadius = 5000.f; // ���� �ݰ�
	AISenseConfig_Sight->LoseSightRadius = 0.f; 
	AISenseConfig_Sight->PeripheralVisionAngleDegrees = 360.f; // �ֺ� �þ߰���

	// Perception ������Ʈ ���� �� �̺�Ʈ ���ε�
	EnemyPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>("EnemyPerceptionComponent");
	EnemyPerceptionComponent->ConfigureSense(*AISenseConfig_Sight);
	EnemyPerceptionComponent->SetDominantSense(UAISenseConfig_Sight::StaticClass());
	EnemyPerceptionComponent->OnTargetPerceptionUpdated.AddUniqueDynamic(this, &ThisClass::OnEnemyPerceptionUpdated);

	// �� ID ���� (AI �� �Ǻ���)
	SetGenericTeamId(FGenericTeamId(1));
}

ETeamAttitude::Type AHunterAIController::GetTeamAttitudeTowards(const AActor& Other) const
{
	const APawn* PawnToCheck = Cast<const APawn>(&Other);

	const IGenericTeamAgentInterface* OtherTeamAgent = Cast<const IGenericTeamAgentInterface>(PawnToCheck->GetController());

	// ��� ���Ͱ� Pawndlrh ���� �ٸ��� ������ ����
	if (OtherTeamAgent && OtherTeamAgent->GetGenericTeamId() != GetGenericTeamId())
	{
		return ETeamAttitude::Hostile;
	}

	return ETeamAttitude::Friendly;
}

void AHunterAIController::BeginPlay()
{
	Super::BeginPlay();

	if (UCrowdFollowingComponent* CrowdComp = Cast<UCrowdFollowingComponent>(GetPathFollowingComponent()))
	{
		// ȸ�� ��� �Ҹ��� ���� ���� �ѱ�/����
		CrowdComp->SetCrowdSimulationState(bEnableDetourCrowdAvoidance ? ECrowdSimulationState::Enabled : ECrowdSimulationState::Disabled);

		// ȸ�� ǰ�� ����
		switch (DetourCrowdAvoidanceQuality)
		{
		case 1: CrowdComp->SetCrowdAvoidanceQuality(ECrowdAvoidanceQuality::Low);		break;
		case 2: CrowdComp->SetCrowdAvoidanceQuality(ECrowdAvoidanceQuality::Medium);	break;
		case 3: CrowdComp->SetCrowdAvoidanceQuality(ECrowdAvoidanceQuality::Good);		break;
		case 4: CrowdComp->SetCrowdAvoidanceQuality(ECrowdAvoidanceQuality::High);		break;
		default:
			break;
		}

		// ȸ�� �׷� ����
		CrowdComp->SetAvoidanceGroup(1);
		CrowdComp->SetGroupsToAvoid(1);
		// �浹 Ž�� ���� ����
		CrowdComp->SetCrowdCollisionQueryRange(CollisionQueryRange);
	}
}

void AHunterAIController::OnEnemyPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	// AI�� �����ߴٸ�
	if (Stimulus.WasSuccessfullySensed() && Actor)
	{
		// �����忡 Ÿ�� ���� ����
		if (UBlackboardComponent* BlackboardComponent = GetBlackboardComponent())
		{
			BlackboardComponent->SetValueAsObject(FName("TargetActor"), Actor);
		}
	}
}
