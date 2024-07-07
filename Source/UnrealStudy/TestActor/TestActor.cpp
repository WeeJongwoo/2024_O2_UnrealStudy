// Fill out your copyright notice in the Description page of Project Settings.

#include "TestActor/TestActor.h"
#include "Log/CLog.h"

DEFINE_LOG_CATEGORY(Wee);

// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Log, TEXT("TestLog"));
	UE_LOG(Wee, Error, TEXT("Wee"));

}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

