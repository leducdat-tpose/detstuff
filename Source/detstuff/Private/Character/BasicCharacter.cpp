// Fill out your copyright notice in the Description page of Project Settings.


#include "detstuff/Public/Character/BasicCharacter.h"

ABasicCharacter::ABasicCharacter(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABasicCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABasicCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABasicCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

