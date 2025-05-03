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
	AISenseConfig_Sight->DetectionByAffiliation.bDetectEnemies = true; // 적만 감지
	AISenseConfig_Sight->DetectionByAffiliation.bDetectFriendlies = false; // 아군 감지
	AISenseConfig_Sight->DetectionByAffiliation.bDetectNeutrals = false; // 중립
	AISenseConfig_Sight->SightRadius = 5000.f; // 측면 반경
	AISenseConfig_Sight->LoseSightRadius = 0.f; 
	AISenseConfig_Sight->PeripheralVisionAngleDegrees = 360.f; // 주변 시야각도

	// Perception 컴포넌트 설정 및 이벤트 바인딩
	EnemyPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>("EnemyPerceptionComponent");
	EnemyPerceptionComponent->ConfigureSense(*AISenseConfig_Sight);
	EnemyPerceptionComponent->SetDominantSense(UAISenseConfig_Sight::StaticClass());
	EnemyPerceptionComponent->OnTargetPerceptionUpdated.AddUniqueDynamic(this, &ThisClass::OnEnemyPerceptionUpdated);

	// 팀 ID 설정 (AI 팀 판별용)
	SetGenericTeamId(FGenericTeamId(1));
}

ETeamAttitude::Type AHunterAIController::GetTeamAttitudeTowards(const AActor& Other) const
{
	const APawn* PawnToCheck = Cast<const APawn>(&Other);

	const IGenericTeamAgentInterface* OtherTeamAgent = Cast<const IGenericTeamAgentInterface>(PawnToCheck->GetController());

	// 상대 액터가 Pawndlrh 팀이 다르면 적으로 간주
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
		// 회피 기능 불리언 값에 따라 켜기/끄기
		CrowdComp->SetCrowdSimulationState(bEnableDetourCrowdAvoidance ? ECrowdSimulationState::Enabled : ECrowdSimulationState::Disabled);

		// 회피 품질 설정
		switch (DetourCrowdAvoidanceQuality)
		{
		case 1: CrowdComp->SetCrowdAvoidanceQuality(ECrowdAvoidanceQuality::Low);		break;
		case 2: CrowdComp->SetCrowdAvoidanceQuality(ECrowdAvoidanceQuality::Medium);	break;
		case 3: CrowdComp->SetCrowdAvoidanceQuality(ECrowdAvoidanceQuality::Good);		break;
		case 4: CrowdComp->SetCrowdAvoidanceQuality(ECrowdAvoidanceQuality::High);		break;
		default:
			break;
		}

		// 회피 그룹 설정
		CrowdComp->SetAvoidanceGroup(1);
		CrowdComp->SetGroupsToAvoid(1);
		// 충돌 탐지 범위 설정
		CrowdComp->SetCrowdCollisionQueryRange(CollisionQueryRange);
	}
}

void AHunterAIController::OnEnemyPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	// AI가 감지했다면
	if (Stimulus.WasSuccessfullySensed() && Actor)
	{
		// 블랙보드에 타겟 액터 저장
		if (UBlackboardComponent* BlackboardComponent = GetBlackboardComponent())
		{
			BlackboardComponent->SetValueAsObject(FName("TargetActor"), Actor);
		}
	}
}
