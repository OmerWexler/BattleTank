// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "Tank.h"


void ATankPlayerController::BeginPlay() 
{
    Super::BeginPlay();

    ATank* ControlledTank = GetControlledTank();
    if (ControlledTank) {
        UE_LOG(LogTemp, Warning, TEXT("Player, %s"), *ControlledTank->GetName());
    }
}

void ATankPlayerController::Tick(float DeltaTime) 
{
    Super::Tick(DeltaTime);

}

ATank* ATankPlayerController::GetControlledTank() const 
{
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimAtCrosshair() 
{
    ATank* ControlledTank = GetControlledTank();
    if (!ControlledTank) return;
    
    FVector HitLocation;
    GetSightHitLocation(HitLocation);
    // Aim
}

bool ATankPlayerController::GetSightHitLocation(FVector& OutHitLocation) const
{
    return false;
}