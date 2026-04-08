// Copyright by dat-tpose


#include "AI/Components/DetStateTreeAIComponent.h"

UDetStateTreeAIComponent::UDetStateTreeAIComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UDetStateTreeAIComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UDetStateTreeAIComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                             FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

