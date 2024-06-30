#include "SimpleShooterGameModeBase.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"

/**********************/
/****PUBLIC METHODS****/
/**********************/

void ASimpleShooterGameModeBase::PawnKilled(APawn *Pawn)
{
	if(APlayerController* PlayerController = Cast<APlayerController>(Pawn->GetController())) { EndGame(false); }
}

/*************************/
/****PROTECTED METHODS****/
/*************************/

void ASimpleShooterGameModeBase::EndGame(bool bIsPlayerWinner)
{
	for(AController* Controller : TActorRange<AController>(GetWorld()))
	{
		Controller->GameHasEnded(
			Controller->GetPawn(),
			(Controller->IsPlayerController() == bIsPlayerWinner)
		);
	}
}