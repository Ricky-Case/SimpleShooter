#include "BTTask_ClearBlackboardValue.h"
#include "BehaviorTree/BlackboardComponent.h"

/**************************/
/******PUBLIC METHODS******/
/**************************/

UBTTask_ClearBlackboardValue::UBTTask_ClearBlackboardValue() { NodeName = TEXT("Clear Blackboard Value"); }

/*************************/
/****PROTECTED METHODS****/
/*************************/

EBTNodeResult::Type UBTTask_ClearBlackboardValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());

	return EBTNodeResult::Succeeded;
}