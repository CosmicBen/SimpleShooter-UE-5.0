// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"

class UUserWidget;

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;

public:
	virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;



private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Game Over", meta = (AllowPrivateAccess = "true"))
	float RestartDelay = 5.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Over", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserWidget> LoseScreenClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Over", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserWidget> WinScreenClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "HUD", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserWidget> HudClass;

	UPROPERTY()
	UUserWidget* HudScreen;
	FTimerHandle RestartTimer;

public:
	bool IsDead() const;
};
