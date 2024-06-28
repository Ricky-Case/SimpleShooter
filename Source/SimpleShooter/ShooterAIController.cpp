#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"

/**************************/
/******PUBLIC METHODS******/
/**************************/

void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(PlayerPawn)
	{
		if(LineOfSightTo(PlayerPawn))
		{
			SetFocus(PlayerPawn);
			MoveToActor(PlayerPawn, AcceptanceRadius);
		}
		else
		{
			ClearFocus(EAIFocusPriority::Gameplay);
			StopMovement();
		}
	}
}

/*************************/
/****PROTECTED METHODS****/
/*************************/

void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), TargetPlayer);
}