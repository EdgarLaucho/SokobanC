// Fill out your copyright notice in the Description page of Project Settings.


#include "SokobanPawn_C.h"
#include "Movable_c.h"

// Sets default values
ASokobanPawn_C::ASokobanPawn_C()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASokobanPawn_C::BeginPlay()
{
	Super::BeginPlay();
	
}
bool ASokobanPawn_C::Move(FVector dir)
{
	FVector desiredPos = GetActorLocation() + dir * MoveStep;

	//ray
	FHitResult hitRes;
	FCollisionQueryParams params;
	params.AddIgnoredActor(this);

	bool bHit = GetWorld()->LineTraceSingleByChannel(hitRes, GetActorLocation(), desiredPos, ECC_WorldStatic, params);
	if (bHit)
	{
		auto actor = hitRes.GetActor();
		if (actor && actor->Implements<UMovable_c>())
		{
			bool bMoved =Cast<IMovable_c>(actor)->DoMove(dir);
			if (bMoved)
			{

				SetActorLocation(desiredPos);
				OnMoved.Broadcast();
				return true;
			}
		}
		return false;
	}
	SetActorLocation(desiredPos);
	OnMoved.Broadcast();
	return true;
}

// Called every frame
void ASokobanPawn_C::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASokobanPawn_C::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

