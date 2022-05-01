// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

class USkeletalMeshComponent;
class UParticleSystem;

UCLASS()
class SIMPLESHOOTER_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	AGun();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;



private:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Shooting", meta = (AllowPrivateAccess = "true"))
	UParticleSystem* MuzzleFlash;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Shooting", meta = (AllowPrivateAccess = "true"))
	USoundBase* MuzzleSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Shooting", meta = (AllowPrivateAccess = "true"))
	UParticleSystem* ImpactEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Shooting", meta = (AllowPrivateAccess = "true"))
	USoundBase* ImpactSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Shooting", meta = (AllowPrivateAccess = "true"))
	float MaxRange = 1000.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Shooting", meta = (AllowPrivateAccess = "true"))
	float Damage = 10.0f;

	bool GunTrace(FHitResult& Hit, FVector& ShotDirection);
	AController* GetOwnerController() const;

public:
	void PullTrigger();
};
