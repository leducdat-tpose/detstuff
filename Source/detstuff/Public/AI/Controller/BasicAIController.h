// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI/Components/DetStateTreeAIComponent.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "BasicAIController.generated.h"

UCLASS()
class DETSTUFF_API ABasicAIController : public AAIController
{
	GENERATED_BODY()

public:
	ABasicAIController(const FObjectInitializer& ObjectInitializer);

protected:

	virtual void OnPossess(APawn* InPawn) override;
	
	virtual void BeginPlay() override;

	virtual void OnUnPossess() override;

public:
	virtual void Tick(float DeltaTime) override;

	UDetStateTreeAIComponent* GetStateTreeComponent() const;
};
