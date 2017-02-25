// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

ATank * ATankAIController::GetControlledTank() const
{
	return  Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* PosessedTank = GetPlayerTank();
	if (!PosessedTank) {
		UE_LOG(LogTemp, Error, TEXT("No controlled tank!"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Posessed tank by player: %s"), *(PosessedTank->GetName()))

	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ATank* PlayerTank = GetPlayerTank();
	if (PlayerTank) {
		GetControlledTank()->AimAt(PlayerTank->GetActorLocation());
	}
}

ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
