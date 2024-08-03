// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/AnimNotify_AttackHitCheck.h"
#include "Interface/O2AnimationAttackInterface.h"

void UAnimNotify_AttackHitCheck::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (MeshComp)
	{
		IO2AnimationAttackInterface* AttackPawn = Cast<IO2AnimationAttackInterface>(MeshComp->GetOwner());
		if (AttackPawn)
		{
			UE_LOG(LogTemp, Log, TEXT("Notify"));
			AttackPawn->AttackHitCheck();
		}
	}
}
