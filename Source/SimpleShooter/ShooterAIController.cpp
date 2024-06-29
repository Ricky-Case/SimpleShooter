#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

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
			GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
			GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownPlayerLocation"), PlayerPawn->GetActorLocation());
		}
		else
		{
			GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
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
	
	if(AIBehavior && PlayerPawn)
	{
		RunBehaviorTree(AIBehavior);

		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
		GetBlackboardComponent()->SetValueAsVector(TEXT("PatrolLocationA"), GetPawn()->GetActorLocation());
		GetBlackboardComponent()->SetValueAsVector(TEXT("PatrolLocationB"), GetPawn()->GetActorLocation() + (GetPawn()->GetActorForwardVector() * PatrolMovementDistance));
	}
}