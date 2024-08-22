// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/O2AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

AO2AIController::AO2AIController()
{
	static ConstructorHelpers::FObjectFinder<UBlackboardData> BBAssetRef(TEXT("/Script/AIModule.BlackboardData'/Game/Blueprint/AI/BB_O2Character.BB_O2Character'"));
	if (BBAssetRef.Object)
	{
		BBAsset = BBAssetRef.Object;
	}

	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTAssetRef(TEXT("/Script/AIModule.BehaviorTree'/Game/Blueprint/AI/BT_O2Character.BT_O2Character'"));
	if (BTAssetRef.Object)
	{
		BTAsset = BTAssetRef.Object;
	}
}

void AO2AIController::RunAI()
{
	UBlackboardComponent* BlackboardPtr = Blackboard.Get();
	if (UseBlackboard(BBAsset, BlackboardPtr))
	{
		Blackboard->SetValueAsVector(TEXT("HomePos"), GetPawn()->GetActorLocation());

		bool RunResult = RunBehaviorTree(BTAsset);
		ensure(RunResult);
	}
}

void AO2AIController::StopAI()
{
	UBehaviorTreeComponent* BTComponent = Cast<UBehaviorTreeComponent>(BrainComponent);
	if (BTComponent)
	{
		BTComponent->StopTree();
	}
}

void AO2AIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	RunAI();
}
