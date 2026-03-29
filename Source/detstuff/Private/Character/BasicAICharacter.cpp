// Fill out your copyright notice in the Description page of Project Settings.


#include "detstuff/Public/Character/BasicAICharacter.h"

ABasicAICharacter::ABasicAICharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABasicAICharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ABasicAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
