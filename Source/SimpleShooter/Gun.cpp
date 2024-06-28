#include "Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
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
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));
	
	AController* OwnerController = Cast<APawn>(GetOwner())->GetController();
	if(!OwnerController) { return; }

	FVector ViewpointLocation;
	FRotator ViewpointRotation;
	
	OwnerController->GetPlayerViewPoint(ViewpointLocation, ViewpointRotation);

	FVector End = (ViewpointLocation + ViewpointRotation.Vector() * FireRange);
	// TODO: Line Tracing
	
	FHitResult HitResult;
	bool bHitSuccess = GetWorld()->LineTraceSingleByChannel(HitResult, ViewpointLocation, End, ECollisionChannel::ECC_GameTraceChannel1);

	if(bHitSuccess)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, HitResult.Location);
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