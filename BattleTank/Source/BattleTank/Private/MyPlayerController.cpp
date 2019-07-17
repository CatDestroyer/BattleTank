// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"


void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player controller not controlling a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is the possessed tank."), *ControlledTank->GetName());
	}
}


void AMyPlayerController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
	AimTowardsCrosshair();
}



ATank* AMyPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void AMyPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
}