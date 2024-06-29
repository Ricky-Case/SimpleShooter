#include "KillEmAllGameMode.h"

void AKillEmAllGameMode::PawnKilled(APawn *Pawn)
{
	Super::PawnKilled(Pawn);
	UE_LOG(LogTemp, Warning, TEXT("PAWN KILLED! %s"), *Pawn->GetActorNameOrLabel());
}
