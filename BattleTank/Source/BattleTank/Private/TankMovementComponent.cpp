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
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMoveForward(ForwardThrow);

	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention);
	IntendTurnRight(RightThrow.GetSafeNormal().Z);

	auto TankName = GetOwner()->GetName();
	//UE_LOG(LogTemp, Warning, TEXT("%s throttle: %s"), *TankName, *MoveVelocityString);
}
