#include "BTService_PlayerLocationIfSeen.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"

/**************************/
/******PUBLIC METHODS******/
/**************************/

UBTService_PlayerLocationIfSeen::UBTService_PlayerLocationIfSeen() { NodeName = TEXT("Update Player Location If Seen"); }

/*************************/
/****PROTECTED METHODS****/
/*************************/

void UBTService_PlayerLocationIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	if(APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), TargetPlayer))
	{
		if(OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn)) { OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), PlayerPawn); }
		else { OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey()); }
	}
}
