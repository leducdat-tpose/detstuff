// Copyright by dat-tpose

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BasicBehaviorTreeComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DETSTUFF_API UBasicBehaviorTreeComponent : public UBehaviorTreeComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UBasicBehaviorTreeComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
