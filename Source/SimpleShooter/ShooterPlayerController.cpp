// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"
#include "ShooterCharacter.h"

void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();

	HudScreen = CreateWidget(this, HudClass);
	if (HudScreen != NULL)
	{
		HudScreen->AddToViewport();
	}
}

void AShooterPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	HudScreen->RemoveFromViewport();

	if (bIsWinner)
	{
		UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);
		if (WinScreen != NULL)
		{
			WinScreen->AddToViewport();
		}
	}
	else
	{
		UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
		if (LoseScreen != NULL)
		{
			LoseScreen->AddToViewport();
		}
	}

	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}

bool AShooterPlayerController::IsDead() const
{
	AShooterCharacter* ControlledCharacter = Cast<AShooterCharacter>(GetPawn());
	if (!ControlledCharacter) { return true; }

	return ControlledCharacter->IsDead();
}