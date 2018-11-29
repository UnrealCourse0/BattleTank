// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "Engine/World.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("%f: Barrel->Elevate() called at speed %f"), Time, RelativeSpeed);

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	auto ClampedElevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	auto Time = GetWorld()->DeltaTimeSeconds;
	//UE_LOG(LogTemp, Warning, TEXT("%f: Elevation Change %f, RawNewElevation %f, Clamped Elevation %f"), Time, ElevationChange, RawNewElevation, ClampedElevation);

	SetRelativeRotation(FRotator(ClampedElevation, 0, 0));
}