// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Solver_C.generated.h"

class UBoxComponent;
class USceneComponent;
class UPrimitiveComponent;
struct FHitResult;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSolverStateChanged, bool, bSolved);

UCLASS()
class SOKOBANEDGAR_API ASolver_C : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASolver_C();

	UFUNCTION(BlueprintCallable, Category = "Solver")
	bool isSolved() const { return bSolved; }

	UPROPERTY(BlueprintAssignable, Category = "Solver")
	FOnSolverStateChanged OnSolverStateChanged;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Solver")
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, Category = "Solver")
	UBoxComponent* BoxCol;

	
	bool bSolved = false;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, 
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

	void UpdateSolverState();


};
