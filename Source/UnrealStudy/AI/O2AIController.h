// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "O2AIController.generated.h"

/**
 * 
 */
UCLASS()
class UNREALSTUDY_API AO2AIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AO2AIController();

	void RunAI();
	void StopAI();

protected:

	virtual void OnPossess(APawn* InPawn) override;

private:

	TObjectPtr<class UBlackboardData> BBAsset;

	TObjectPtr<class UBehaviorTree> BTAsset;
	
};
