#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterCharacter.h"

/**************************/
/******PUBLIC METHODS******/
/**************************/

void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AShooterAIController::IsDead() const
{
	if(AShooterCharacter* ControlledCharacter = Cast<AShooterCharacter>(GetPawn())) { return ControlledCharacter->IsDead(); }
	else { return true; }
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