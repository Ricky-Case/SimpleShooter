#include "KillEmAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"

/*************************/
/****PROTECTED METHODS****/
/*************************/

void AKillEmAllGameMode::PawnKilled(APawn *Pawn)
{
	Super::PawnKilled(Pawn);

	if(APlayerController* PlayerController = Cast<APlayerController>(Pawn->GetController()))
	{
		EndGame(false);
	}
	else
	{
		for(AShooterAIController* AIController : TActorRange<AShooterAIController>(GetWorld())) { if(!AIController->IsDead()) { return; } }
		EndGame(true);
	}
}

/***********************/
/****PRIVATE METHODS****/
/***********************/

void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner) const
{
	for(AController* Controller : TActorRange<AController>(GetWorld()))
	{
		Controller->GameHasEnded(
			Controller->GetPawn(),
			(Controller->IsPlayerController() == bIsPlayerWinner)
		);
	}
}