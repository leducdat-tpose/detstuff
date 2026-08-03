// Copyright by dat-tpose

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NavMeshDetectVolume.generated.h"

USTRUCT(BlueprintType)
struct FNavMeshEdgeLine : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "NavMesh|Edge")
	TArray<FVector> Edges = {};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "NavMesh|Edge")
	bool bTestingValue = false;
};

UCLASS(Abstract, BlueprintType, Blueprintable, HideCategories=(LevelInstance, WorldPartition, DataLayers, Physics, HLOD, Replication, Networking, Input, Mobile, RayTracing, Cooking, Rendering, Collision, Navigation, AssetUserData))
class DETAIFRAMEWORK_API ANavMeshDetectVolume : public AActor
{
	GENERATED_BODY()

public:
	ANavMeshDetectVolume(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void BeginPlay() override;

	UFUNCTION(CallInEditor, Category = "Debug")
	virtual void ShowDebug();

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Components")
	class UBoxComponent* BoxCollision;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Components")
	FNavMeshEdgeLine EdgeLine;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Components")
	int NumCutBox = 6;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Components")
	float TimeDrawDebug = 5.0f;
public:
	virtual void Tick(float DeltaTime) override;
};
