#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterCharacterController.generated.h"

class UUserWidget;

class AActor;

UCLASS()
class SIMPLESHOOTER_API AShooterCharacterController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void GameHasEnded(AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> LoseScreenClass;

	UPROPERTY(EditAnywhere)
	float RestartDelay = 5.0f;

	FTimerHandle RestartTimer;
};
