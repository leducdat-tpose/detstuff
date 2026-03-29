// Fill out your copyright notice in the Description page of Project Settings.


#include "detstuff/Public/Character/Controller/BasicAIController.h"


// Sets default values
ABasicAIController::ABasicAIController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABasicAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ABasicAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

