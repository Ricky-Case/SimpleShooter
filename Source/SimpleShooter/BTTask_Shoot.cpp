#include "BTTask_Shoot.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "ShooterCharacter.h"

/**************************/
/******PUBLIC METHODS******/
/**************************/

UBTTask_Shoot::UBTTask_Shoot() { NodeName = TEXT("Shoot"); }

/*************************/
/****PROTECTED METHODS****/
/*************************/

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if(AShooterCharacter* Character = Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn()))
	{
		Character->Shoot();
		
		return EBTNodeResult::Succeeded;
	}
	else
	{
		return EBTNodeResult::Failed;
	}
}