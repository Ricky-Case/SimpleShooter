#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"

/**************************/
/******PUBLIC METHODS******/
/**************************/

void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveToActor(PlayerPawn, 100);
}

/*************************/
/****PROTECTED METHODS****/
/*************************/

void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if(PlayerPawn) { SetFocus(PlayerPawn); }
}