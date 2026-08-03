// Copyright by dat-tpose

#pragma once

#include "CoreMinimal.h"
#include "NavMeshDetectVolume.h"
#include "NavMeshDetectEdgeVolume.generated.h"

UCLASS(BlueprintType, Blueprintable)
class DETAIFRAMEWORK_API ANavMeshDetectEdgeVolume : public ANavMeshDetectVolume
{
	GENERATED_BODY()

public:
	ANavMeshDetectEdgeVolume(const FObjectInitializer& Initializer);

	UFUNCTION(CallInEditor)
	void DrawDebugNavMesh();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	double DistBtwFloors = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	float DrawDebugTime = 5.0f;
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
