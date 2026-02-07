// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SokobanPawn_C.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPawnMoved);

UCLASS()
class SOKOBANEDGAR_API ASokobanPawn_C : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASokobanPawn_C();

	UFUNCTION(BlueprintCallable, Category = "MovePawn")
	bool Move(FVector dir);

	UPROPERTY(BlueprintAssignable, Category = "Delegates")
	FOnPawnMoved OnMoved;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pawn")
	float MoveStep = 100.0f;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
