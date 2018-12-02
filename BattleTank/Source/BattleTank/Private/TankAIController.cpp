// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerPawn = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (PlayerPawn)
	{
		// TODO move towards the player

		// Aim towards the player
		auto AITank = Cast<ATank>(GetPawn());
		AITank->AimAt(PlayerPawn->GetActorLocation());

		AITank->Fire();
	}
}

