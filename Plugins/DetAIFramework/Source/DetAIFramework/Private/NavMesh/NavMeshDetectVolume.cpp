// Copyright by dat-tpose


#include "NavMesh/NavMeshDetectVolume.h"

#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"

ANavMeshDetectVolume::ANavMeshDetectVolume(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	RootComponent = BoxCollision;

	BoxCollision->SetBoxExtent(FVector(100.0f, 100.0f, 100.0f));
	BoxCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	BoxCollision->SetCollisionResponseToAllChannels(ECR_Ignore);
	BoxCollision->SetGenerateOverlapEvents(false);
	BoxCollision->Mobility = EComponentMobility::Static;
}

void ANavMeshDetectVolume::BeginPlay()
{
	Super::BeginPlay();
}


void ANavMeshDetectVolume::ShowDebug()
{
#if UE_BUILD_DEVELOPMENT
	
#endif
}

void ANavMeshDetectVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
