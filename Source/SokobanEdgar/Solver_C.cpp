// Fill out your copyright notice in the Description page of Project Settings.


#include "Solver_C.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"
#include "Movable_c.h"

// Sets default values
ASolver_C::ASolver_C()
{
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	BoxCol = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCol"));
	BoxCol->SetupAttachment(Root);

	BoxCol->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxCol->SetCollisionObjectType(ECC_WorldStatic);

	BoxCol->SetCollisionResponseToAllChannels(ECR_Ignore);
	BoxCol->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	BoxCol->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Overlap);
	BoxCol->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);;


}

// Called when the game starts or when spawned
void ASolver_C::BeginPlay()
{
	Super::BeginPlay();

	BoxCol->OnComponentBeginOverlap.AddDynamic(this, &ASolver_C::OnOverlapBegin);
	BoxCol->OnComponentEndOverlap.AddDynamic(this, &ASolver_C::OnOverlapEnd);

	UpdateSolverState();
	
}

void ASolver_C::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UpdateSolverState();
}

void ASolver_C::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UpdateSolverState();
}

void ASolver_C::UpdateSolverState()
{
	TArray<AActor*> OverlappingActors;
	BoxCol->GetOverlappingActors(OverlappingActors);

	bool bNowSolved = false;

	for (AActor* Actor : OverlappingActors)
	{
		if (Actor && Actor->Implements<UMovable_c>()) 
		{
			bNowSolved = true;
			break;
		}
	}

	if (bNowSolved != bSolved)
	{
		bSolved = bNowSolved;
		OnSolverStateChanged.Broadcast(bSolved);
	}
}
