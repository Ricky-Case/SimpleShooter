#include "ShooterCharacterController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

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

	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}
