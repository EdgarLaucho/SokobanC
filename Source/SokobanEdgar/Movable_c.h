// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Movable_c.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMovable_c : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SOKOBANEDGAR_API IMovable_c
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual bool DoMove(FVector dir) { return false; };
};
