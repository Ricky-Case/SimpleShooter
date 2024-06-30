#include "ShooterCharacterController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

/**************************/
/******PUBLIC METHODS******/
/**************************/

void AShooterCharacterController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	if(bIsWinner)
	{
		if(UUserWidget* WinScreen = CreateWidget(this, WinScreenClass)) { WinScreen->AddToViewport(); }
	}
	else
	{
		if(UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass)) { LoseScreen->AddToViewport(); }
	}

	if(HUD) { HUD->RemoveFromParent(); }

	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}

/*************************/
/****PROTECTED METHODS****/
/*************************/

void AShooterCharacterController::BeginPlay()
{
	Super::BeginPlay();

	HUD = CreateWidget(this, HUDClass);
	if(HUD) { HUD->AddToViewport(); }
}
