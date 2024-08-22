// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/O2CharacterBase.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AO2CharacterBase::AO2CharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCapsuleComponent()->InitCapsuleSize(50.f, 100.f);
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Player"));

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.0f, 0.f);
	GetCharacterMovement()->JumpZVelocity = 700.0f;
	GetCharacterMovement()->AirControl = 0.32f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.0f;

	//Mesh
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -100.0f), FRotator(0.0f, -90.f, 0.0f));
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	GetMesh()->SetCollisionProfileName(TEXT("NoCollision"));

}

void AO2CharacterBase::AttackHitCheck()
{

	TArray<FHitResult> OutHitResults;
	FCollisionQueryParams Params(SCENE_QUERY_STAT(Attack), false, this);

	const float AttackRange = 200.0f;
	const FVector Start = GetActorLocation() + GetActorForwardVector() * GetCapsuleComponent()->GetScaledCapsuleRadius();
	const FVector End = Start + GetActorForwardVector() * AttackRange;
	const FVector AttackBoxHalfExtent(25.0f, 25.0f, 25.0f);

	bool IsHit = GetWorld()->SweepMultiByChannel(OutHitResults, Start, End, FQuat::Identity,ECC_GameTraceChannel1, 
		FCollisionShape::MakeBox(AttackBoxHalfExtent), Params);

	FColor DebugColor = IsHit ? FColor::Green : FColor::Red;
	FVector DebugBoxExtent = AttackBoxHalfExtent + FVector(0.0f, 0.0f, AttackRange/2);

	DrawDebugBox(GetWorld(), Start + (End - Start) * 0.5f, DebugBoxExtent, FRotationMatrix::MakeFromZ(GetActorForwardVector()).ToQuat(), 
		DebugColor, false, 5.0f);
	UE_LOG(LogTemp, Log, TEXT("Hit Target Num: %d"), OutHitResults.Num());
}

void AO2CharacterBase::AttackAnimationStart()
{
	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_None);

	const float AnimationRate = 1.0f;
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	AnimInstance->Montage_Play(AttackActionMontage, AnimationRate);

	FOnMontageEnded EndDelegate;
	EndDelegate.BindUObject(this, &AO2CharacterBase::AttackEnd);
	AnimInstance->Montage_SetEndDelegate(EndDelegate, AttackActionMontage);
}

void AO2CharacterBase::AttackEnd(class UAnimMontage* TargetMontage, bool IsProperlyEnded)
{
	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);
}


