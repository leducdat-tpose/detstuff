// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "BasicAIController.generated.h"

UCLASS()
class DETSTUFF_API ABasicAIController : public AAIController
{
	GENERATED_BODY()

public:
	ABasicAIController(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
