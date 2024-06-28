#include "ShooterCharacter.h"
#include "Components/SkinnedMeshComponent.h"
#include "Gun.h"

/**************************/
/******PUBLIC METHODS******/
/**************************/

AShooterCharacter::AShooterCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if(PlayerInputComponent)
	{
		PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
		PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
		PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APawn::AddControllerYawInput);

		PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Pressed, this, &AShooterCharacter::Shoot);
		PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AShooterCharacter::MoveForward);
		PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AShooterCharacter::MoveRight);
		PlayerInputComponent->BindAxis(TEXT("LookUpRate"), this, &AShooterCharacter::LookUpRate);
		PlayerInputComponent->BindAxis(TEXT("TurnRate"), this, &AShooterCharacter::TurnRate);
	}
}

float AShooterCharacter::TakeDamage(float DamageAmount, FDamageEvent const &DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float DamageToApply = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	Health -= FMath::Min(Health, DamageToApply);

	UE_LOG(LogTemp, Warning, TEXT("DAMAGE TAKEN! -- HEALTH: %f"), Health);

	return DamageToApply;
}

bool AShooterCharacter::IsDead() const { return (Health <= 0); }

/*************************/
/****PROTECTED METHODS****/
/*************************/

void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;

	Gun = GetWorld()->SpawnActor<AGun>(GunClass);
	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
	Gun->SetOwner(this);
}

/***************************/
/******PRIVATE METHODS******/
/***************************/

void AShooterCharacter::MoveForward(float AxisValue) { AddMovementInput(GetActorForwardVector() * AxisValue); }
void AShooterCharacter::MoveRight(float AxisValue) { AddMovementInput(GetActorRightVector() * AxisValue); }
void AShooterCharacter::LookUpRate(float AxisValue) { AddControllerPitchInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds()); }
void AShooterCharacter::TurnRate(float AxisValue) { AddControllerYawInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds()); }
void AShooterCharacter::Shoot() { Gun->PullTrigger(); }