// Copyright by dat-tpose

#pragma once

#include "CoreMinimal.h"
#include "Components/StateTreeAIComponent.h"
#include "DetStateTreeAIComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DETSTUFF_API UDetStateTreeAIComponent : public UStateTreeAIComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UDetStateTreeAIComponent(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
