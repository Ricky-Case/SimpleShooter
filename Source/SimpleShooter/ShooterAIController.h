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
	bool IsDead() const;

protected:
	virtual void BeginPlay() override;

private:
	APawn* PlayerPawn = nullptr;

	UPROPERTY(EditAnywhere)
	int32 TargetPlayer = 0;
	UPROPERTY(EditAnywhere)
	float PatrolMovementDistance = 1500.0f;
	UPROPERTY(EditAnywhere)
	UBehaviorTree* AIBehavior;
};
