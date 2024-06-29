#include "SimpleShooterGameModeBase.h"

/*************************/
/****PROTECTED METHODS****/
/*************************/

void ASimpleShooterGameModeBase::PawnKilled(APawn *Pawn)
{
	if(APlayerController* PlayerController = Cast<APlayerController>(Pawn->GetController())) { PlayerController->GameHasEnded(nullptr, false); }

	UE_LOG(LogTemp, Warning, TEXT("%s HAS BEEN KILLED!"), *Pawn->GetActorNameOrLabel());
}
