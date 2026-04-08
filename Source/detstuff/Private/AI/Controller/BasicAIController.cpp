// Fill out your copyright notice in the Description page of Project Settings.


#include "detstuff/Public/AI/Controller/BasicAIController.h"
#include "AI/Components/DetStateTreeAIComponent.h"
#include "Character/BasicAICharacter.h"

// Sets default values
ABasicAIController::ABasicAIController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UDetStateTreeAIComponent>("DetStateTreeAIComponent"))
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABasicAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if (!IsValid(InPawn)) return;
	if (const ABasicAICharacter* Character = Cast<ABasicAICharacter>(InPawn))
	{
		if (auto StateTree = Character->GetStateTree())
		if (auto StateTreeComponent = GetStateTreeComponent())
		{
			StateTreeComponent->SetStateTree(StateTree);
		}
	}
}

void ABasicAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ABasicAIController::OnUnPossess()
{
	Super::OnUnPossess();
}

void ABasicAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

UDetStateTreeAIComponent* ABasicAIController::GetStateTreeComponent() const
{
	if (BrainComponent)
	{
		if (auto StateTreeComponent = Cast<UDetStateTreeAIComponent>(BrainComponent))
		{
			return StateTreeComponent;
		}
	}
	return nullptr;
}
