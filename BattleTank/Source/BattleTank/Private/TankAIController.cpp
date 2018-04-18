// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include ""
#include "..\Public\TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possesing: %s"), *(ControlledTank->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	ATank* myTank = Cast<ATank>(GetPawn());

	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstLocalPlayerFromController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	
	return Cast<ATank>(PlayerPawn);
}

