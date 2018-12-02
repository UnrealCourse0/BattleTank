// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankPlayerController.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet)
{
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	// Calculate the OutLaunchVelocity

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace,
		FCollisionResponseParams::DefaultResponseParam,
		TArray<AActor*>(),
		false
	);

	auto TankName = GetOwner()->GetName();
	auto BarrelLocation = Barrel->GetComponentLocation().ToString();

	//if (PreviousHitLocation != HitLocation && bHaveAimSolution)
	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from %s"), *TankName, *HitLocation.ToString(), *BarrelLocation);
		//auto Time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT("%f: Aim solution found for %s"), Time, *TankName);
		MoveBarrelTowards(AimDirection);

		UE_LOG(LogTemp, Warning, TEXT("OutLaunchVelocity = %s"), *OutLaunchVelocity.GetSafeNormal().ToString());
		
	}
	else
	{
		float count = 1;
		bool bHaveAimSolutionBackup = false;

		while (!bHaveAimSolutionBackup)
		{
			bHaveAimSolutionBackup = UGameplayStatics::SuggestProjectileVelocity(
				this,
				OutLaunchVelocity,
				StartLocation,
				HitLocation,
				LaunchSpeed * count,
				false,
				0,
				0,
				ESuggestProjVelocityTraceOption::DoNotTrace,
				FCollisionResponseParams::DefaultResponseParam,
				TArray<AActor*>(),
				false
			);
			count++;
		}
		MoveBarrelTowards(OutLaunchVelocity.GetSafeNormal());
		UE_LOG(LogTemp, Warning, TEXT("OutLaunchVelocity = %s, count = %f"), *OutLaunchVelocity.GetSafeNormal().ToString(), count);

	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// Work-out difference between current barrel rotation, and AimDirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	//UE_LOG(LogTemp, Warning, TEXT("AimAsRotator: %s"), *DeltaRotator.ToString());

	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);

}