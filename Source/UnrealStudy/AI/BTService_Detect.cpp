// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTService_Detect.h"
#include "AIController.h"
#include "Interface/O2CharacterAIInterface.h"
#include "BehaviorTree/BlackboardComponent.h"


UBTService_Detect::UBTService_Detect()
{
	NodeName = TEXT("Detect");
	Interval = 1.0f;
}

void UBTService_Detect::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (ControllingPawn == nullptr)
	{
		return;
	}

	FVector Center = ControllingPawn->GetActorLocation();
	UWorld* World = ControllingPawn->GetWorld();
	if (World == nullptr)
	{
		return;
	}

	IO2CharacterAIInterface* AIPawn = Cast<IO2CharacterAIInterface>(ControllingPawn);
	if (AIPawn == nullptr)
	{
		return;
	}

	float DetecteRadius = AIPawn->GetAIDetectRange();

	TArray<FOverlapResult> OutHitResults;
	FCollisionQueryParams Params(SCENE_QUERY_STAT(Detect), false, ControllingPawn);

	bool IsHit = World->OverlapMultiByChannel(
		OutHitResults,
		Center,
		FQuat::Identity,
		ECC_GameTraceChannel1,
		FCollisionShape::MakeSphere(DetecteRadius),
		Params
	);

	if (IsHit)
	{
		for (auto OvelapResult : OutHitResults)
		{
			APawn* Pawn = Cast<APawn>(OvelapResult.GetActor());
			if (Pawn && Pawn->GetController()->IsPlayerController())
			{
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(TEXT("Target"), Pawn);
				return;
			}
		}
	}

	OwnerComp.GetBlackboardComponent()->SetValueAsObject(TEXT("Target"), nullptr);
}
