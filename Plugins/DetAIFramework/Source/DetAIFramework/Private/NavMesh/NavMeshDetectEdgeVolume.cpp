// Copyright by dat-tpose


#include "NavMesh/NavMeshDetectEdgeVolume.h"

#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"


ANavMeshDetectEdgeVolume::ANavMeshDetectEdgeVolume(const FObjectInitializer& Initializer)
	: Super(Initializer)
{
	PrimaryActorTick.bCanEverTick = true;
}

void ANavMeshDetectEdgeVolume::DrawDebugNavMesh()
{
	if (!IsValid(BoxCollision)) return;

	FVector BoxExtent = BoxCollision->GetScaledBoxExtent();
	double BoxExtentZ = BoxExtent.Z;
	
	double Divisor = BoxExtentZ * 2.0f;
	double Remains = 0.0f;
	int TotalBoxes = UKismetMathLibrary::FMod64(Divisor, DistBtwFloors, Remains);

	FVector BoxOrigin = BoxCollision->GetComponentLocation();
	FVector BoxOriginFloor = FVector(BoxOrigin.X, BoxOrigin.Y, BoxOrigin.Z - BoxExtentZ + DistBtwFloors/2.0f);
	FVector ExtentXY = FVector(BoxExtent.X, BoxExtent.Y, 0);
	for (int Index = 0; Index < TotalBoxes; Index++)
	{
		FBox SubBox = UKismetMathLibrary::MakeBoxWithOrigin(FVector(BoxOriginFloor.X,
			BoxOriginFloor.Y,
			BoxOriginFloor.Z + Index * DistBtwFloors),
			FVector(BoxExtent.X, BoxExtent.Y, DistBtwFloors/2.0f));

		DrawDebugBox(GetWorld(), SubBox.GetCenter(), SubBox.GetExtent(), FColor::Blue, false, DrawDebugTime, 0, 1.2f);
	}
	if (Remains)
	{
		FBox RemainBox = UKismetMathLibrary::MakeBoxWithOrigin(FVector(BoxOriginFloor.X,
			BoxOriginFloor.Y,
			BoxOriginFloor.Z + (TotalBoxes - 1) * DistBtwFloors + DistBtwFloors/2 + Remains/2),
			FVector(BoxExtent.X, BoxExtent.Y, Remains/2));
		DrawDebugBox(GetWorld(), RemainBox.GetCenter(), RemainBox.GetExtent(), FColor::Yellow, false, DrawDebugTime, 0, 1.2f);
	}
}

void ANavMeshDetectEdgeVolume::BeginPlay()
{
	Super::BeginPlay();
}

void ANavMeshDetectEdgeVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
