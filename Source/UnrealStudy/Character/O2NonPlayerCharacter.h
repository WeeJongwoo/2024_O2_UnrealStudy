// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/O2CharacterBase.h"
#include "Interface/O2CharacterAIInterface.h"
#include "O2NonPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class UNREALSTUDY_API AO2NonPlayerCharacter : public AO2CharacterBase, public IO2CharacterAIInterface
{
	GENERATED_BODY()
	
public:
	AO2NonPlayerCharacter();
	
protected:
	virtual float GetAIPatrolRadius() override;
	virtual float GetAIDetectRange() override;
};
