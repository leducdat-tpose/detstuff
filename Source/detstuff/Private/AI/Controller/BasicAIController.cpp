// Fill out your copyright notice in the Description page of Project Settings.


#include "detstuff/Public/AI/Controller/BasicAIController.h"

#include "AI/Components/BasicBehaviorTreeComponent.h"
#include "AI/Components/BasicPathFollowingComponent.h"
#include "AI/Components/BasicPerceptionComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "Character/BasicAICharacter.h"

// Sets default values
ABasicAIController::ABasicAIController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer
		.SetDefaultSubobjectClass<UBasicPerceptionComponent>("PerceptionComponent")
		.SetDefaultSubobjectClass<UBasicPathFollowingComponent>("PathFollowingComponent"))
{
	PrimaryActorTick.bCanEverTick = true;
	bStartAILogicOnPossess = false;

	BrainComponent = CreateDefaultSubobject<UBasicBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	PerceptionComponent = CreateDefaultSubobject<UBasicPerceptionComponent>(TEXT("PerceptionComponent"));
}

void ABasicAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
}

void ABasicAIController::BeginPlay()
{
	Super::BeginPlay();
	if (const ABasicAICharacter* BasicAICharacter = Cast<ABasicAICharacter>(GetPawn()))
	{
		if (const UBehaviorTree* InBT = BasicAICharacter->GetBehaviorTree())
		{
			RunBehaviorTree(const_cast<UBehaviorTree*>(InBT));
		}
	}
}

void ABasicAIController::OnUnPossess()
{
	Super::OnUnPossess();
}

void ABasicAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

UBehaviorTreeComponent* ABasicAIController::GetBehaviorTreeComponent() const
{
	if (IsValid(BrainComponent))
	{
		if (UBehaviorTreeComponent* BTC = Cast<UBehaviorTreeComponent>(BrainComponent))
		{
			return BTC;
		}
	}
	return nullptr;
}
