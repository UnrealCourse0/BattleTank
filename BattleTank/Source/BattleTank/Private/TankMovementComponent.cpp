// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::InitializeComponent(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	Left = LeftTrackToSet;
	Right = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!Left || !Right) { return; }
	Left->SetThrottle(Throw);
	Right->SetThrottle(Throw);
	//TODO prevent double move due to dual control
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!Left || !Right) { return; }
	Left->SetThrottle(Throw);
	Right->SetThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	auto TankName = GetOwner()->GetName();
	auto MoveVelocityString = MoveVelocity.ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s throttle: %s"), *TankName, *MoveVelocityString);
}
