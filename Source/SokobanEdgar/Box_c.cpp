// Fill out your copyright notice in the Description page of Project Settings.


#include "Box_c.h"

// Sets default values
ABox_c::ABox_c()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

bool ABox_c::DoMove(FVector dir)
{
	FVector desiredPos = GetActorLocation() + dir * MoveStep;

	//ray
	FHitResult hitRes;
	FCollisionQueryParams params;
	params.AddIgnoredActor(this);

	bool bHit = GetWorld()->LineTraceSingleByChannel(hitRes, GetActorLocation(), desiredPos, ECC_WorldStatic, params);
	if (bHit)
	{
		return false;
	}
	SetActorLocation(desiredPos);
	return true;
	
}

// Called when the game starts or when spawned
void ABox_c::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABox_c::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

