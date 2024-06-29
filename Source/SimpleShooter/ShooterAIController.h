#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"

class UBehaviorTree;

UCLASS()
class SIMPLESHOOTER_API AShooterAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	APawn* PlayerPawn = nullptr;

	UPROPERTY(EditAnywhere)
	int32 TargetPlayer = 0;
	UPROPERTY(EditAnywhere)
	int32 PatrolMovementDistance = 3000.0f;
	UPROPERTY(EditAnywhere)
	UBehaviorTree* AIBehavior;
};
