// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/O2AnimationAttackInterface.h"
#include "O2CharacterBase.generated.h"


UCLASS()
class UNREALSTUDY_API AO2CharacterBase : public ACharacter, public IO2AnimationAttackInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AO2CharacterBase();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UAnimMontage> AttackActionMontage;

	virtual void AttackHitCheck() override;
	void AttackAnimationStart();
	void AttackEnd(class UAnimMontage* TargetMontage, bool IsProperlyEnded);

};
