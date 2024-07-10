// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/O2PlayerController.h"

void AO2PlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameOnly GameInputMode;
	SetInputMode(GameInputMode);
}