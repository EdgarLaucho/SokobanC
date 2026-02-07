// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Movable_c.h"
#include "Box_c.generated.h"

UCLASS()
class SOKOBANEDGAR_API ABox_c : public AActor, public IMovable_c
{
	GENERATED_BODY()
	
public:	

	
	// Sets default values for this actor's properties
	ABox_c();

	virtual bool DoMove(FVector dir) override;

	float MoveStep = 100.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
