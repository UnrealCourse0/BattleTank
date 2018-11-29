// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "Engine/World.h"

void UTankTurret::Rotate(float RelativeSpeed)
{

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;

	//auto ClampedElevation = FMath::Clamp<float>(RawNewRotation, MinElevationDegrees, MaxElevationDegrees);

	auto Time = GetWorld()->DeltaTimeSeconds;

	UE_LOG(LogTemp, Warning, TEXT("%f: RotationChange %f, RawNewRotation %f"), Time, RotationChange, RawNewRotation);

	SetRelativeRotation(FRotator(0, RawNewRotation, 0));


}