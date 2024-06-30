#include "Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/DamageEvents.h"
#include "DrawDebugHelpers.h"

/**************************/
/******PUBLIC METHODS******/
/**************************/

AGun::AGun()
{
 	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
}

void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGun::PullTrigger()
{
	if(AController* OwnerController = GetOwnerController())
	{
		UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));
		FHitResult HitResult;
		FVector ShotDirection;

		bool bHitSuccess = ExecuteGunTrace(HitResult, ShotDirection, OwnerController);

		if(bHitSuccess)
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, HitResult.Location);
			
			if(AActor* HitActor = HitResult.GetActor())
			{
				FPointDamageEvent DamageEvent(Damage, HitResult, ShotDirection, nullptr);
				HitActor->TakeDamage(Damage, DamageEvent, OwnerController, this);
			}
		}
	}
}

/*************************/
/****PROTECTED METHODS****/
/*************************/

void AGun::BeginPlay()
{
	Super::BeginPlay();
}

/***************************/
/******PRIVATE METHODS******/
/***************************/

bool AGun::ExecuteGunTrace(FHitResult &HitResultOut, FVector &ShotDirectionOut, AController* OwnerController)
{
	FVector Location;
	FRotator Rotation;
	OwnerController->GetPlayerViewPoint(Location, Rotation);
	ShotDirectionOut = -Rotation.Vector();

	FVector End = Location + Rotation.Vector() * FireRange;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());
	return GetWorld()->LineTraceSingleByChannel(HitResultOut, Location, End, ECollisionChannel::ECC_GameTraceChannel1, Params);
}

AController* AGun::GetOwnerController() const { return Cast<APawn>(GetOwner())->GetController(); }