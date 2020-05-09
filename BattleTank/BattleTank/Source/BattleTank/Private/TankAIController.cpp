// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"
#include "TankPlayerController.h"


void ATankAIController::BeginPlay() 
{
    Super::BeginPlay();

    ATank* ControlledTank = GetPlayerTank();
    if (ControlledTank) {
        UE_LOG(LogTemp, Warning, TEXT("AI, %s"), *ControlledTank->GetName());
    }
}

ATank* ATankAIController::GetControlledTank() const 
{
    return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const 
{   
    ATankPlayerController* PlayerController = Cast<ATankPlayerController>(GetWorld()->GetFirstPlayerController());
    return Cast<ATank>(PlayerController->GetControlledTank());
}
