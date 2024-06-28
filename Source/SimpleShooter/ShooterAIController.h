#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"

class AShooterCharacter;

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
	int TargetPlayer = 0;
	UPROPERTY(EditAnywhere)
	float AcceptanceRadius = 200.0f;
};
