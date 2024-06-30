#include "ShooterCharacterController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void AShooterCharacterController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	if(UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass))
	{
		LoseScreen->AddToViewport();
	}

	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}
