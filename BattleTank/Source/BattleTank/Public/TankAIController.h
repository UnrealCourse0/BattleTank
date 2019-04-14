// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Engine/World.h"
#include "Gameframework/Pawn.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "BattleTank.h"
#include "TankAIController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	// How close the AI tank get can to the player tank
	float AcceptanceRadius = 3000;
};
