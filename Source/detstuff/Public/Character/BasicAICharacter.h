// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicCharacter.h"

#include "BasicAICharacter.generated.h"

class UBehaviorTree;
class UStateTree;

UCLASS(Blueprintable)
class DETSTUFF_API ABasicAICharacter : public ABasicCharacter
{
	GENERATED_BODY()

public:
	ABasicAICharacter(const FObjectInitializer& ObjectInitializer);
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "AI Config")
	TObjectPtr<UBehaviorTree> BehaviorTree;

	FORCEINLINE const UBehaviorTree* GetBehaviorTree() const { return BehaviorTree; }
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
