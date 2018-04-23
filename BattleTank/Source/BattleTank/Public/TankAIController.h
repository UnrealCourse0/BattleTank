// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Engine/World.h"
#include "Gameframework/Pawn.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;

	ATank* GetPlayerTank() const;
};
