// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/O2NonPlayerCharacter.h"
#include "AI/O2AIController.h"

AO2NonPlayerCharacter::AO2NonPlayerCharacter()
{

	AIControllerClass = AO2AIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

float AO2NonPlayerCharacter::GetAIPatrolRadius()
{
	return 800.0f;
}

float AO2NonPlayerCharacter::GetAIDetectRange()
{
	return 400.0f;
}
