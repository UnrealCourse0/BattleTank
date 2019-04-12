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