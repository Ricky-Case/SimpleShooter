#include "BTService_PlayerLocation.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

/**************************/
/******PUBLIC METHODS******/
/**************************/

UBTService_PlayerLocation::UBTService_PlayerLocation() { NodeName = TEXT("Update Player Location"); }

/*************************/
/****PROTECTED METHODS****/
/*************************/

void UBTService_PlayerLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	if(APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), TargetPlayer))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerPawn->GetActorLocation());
	}
}