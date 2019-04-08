// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "BattleTank.h"

void UTankTrack::SetThrottle(float Throttle)
{
	//auto Time = GetWorld()->DeltaTimeSeconds;
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"), *Name, Throttle);

	//TODO clamp actual throttle value so player can't over-drive
}