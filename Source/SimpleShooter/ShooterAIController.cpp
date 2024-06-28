#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

/**************************/
/******PUBLIC METHODS******/
/**************************/

void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// if(PlayerPawn)
	// {
	// 	if(LineOfSightTo(PlayerPawn))
	// 	{
	// 		SetFocus(PlayerPawn);
	// 		MoveToActor(PlayerPawn, AcceptanceRadius);
	// 	}
	// 	else
	// 	{
	// 		ClearFocus(EAIFocusPriority::Gameplay);
	// 		StopMovement();
	// 	}
	// }
}

/*************************/
/****PROTECTED METHODS****/
/*************************/

void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), TargetPlayer);
	
	if(AIBehavior && PlayerPawn)
	{
		RunBehaviorTree(AIBehavior);

		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
	}
}