// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "PlayerController_C.generated.h"


class UInputMappingContext;
class UInputAction;
class UUserWidget;

/**
 * 
 */
UCLASS()
class SOKOBANEDGAR_API APlayerController_C : public APlayerController
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, Category="Input")
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* IA_Move;
	
	UPROPERTY(BlueprintReadWrite, Category = "Input")
	bool CanMove = true;

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	void OnMove(const FInputActionValue& Value);

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UUserWidget> HUDWidgetClass;
protected:
	UUserWidget* HUDWidget;

};
