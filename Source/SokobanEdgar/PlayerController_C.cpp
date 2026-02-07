// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController_C.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "SokobanPawn_C.h"
#include "Blueprint/UserWidget.h"




void APlayerController_C::BeginPlay()
{
	Super::BeginPlay();
	if (UEnhancedInputLocalPlayerSubsystem* Subsys = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{

		if (Subsys)
		{
			Subsys->AddMappingContext(DefaultMappingContext, 0);
		}

	}
	if (HUDWidgetClass)
	{
		HUDWidget = CreateWidget<UUserWidget>(this, HUDWidgetClass);
		if (HUDWidget)
		{
			HUDWidget->AddToViewport();
		}
	}
}
void APlayerController_C::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent);
		if (!EnhancedInput) return;

	
	EnhancedInput->BindAction(IA_Move, ETriggerEvent::Started, this, &APlayerController_C::OnMove);

	
}

void APlayerController_C::OnMove(const FInputActionValue& Value)
{
	if (!CanMove) return;
	
	ASokobanPawn_C* pawn = Cast<ASokobanPawn_C>(GetPawn());
	if(pawn)
	{
		FVector2D Input = Value.Get<FVector2D>();

		if (FMath::Abs(Input.X) > 0)
		{
			FVector dir(Input.X, 0, 0);
			pawn->Move(dir);
		}
		else 
		{
			FVector dir( 0, Input.Y, 0);
			pawn->Move(dir);
		}
	}

}
