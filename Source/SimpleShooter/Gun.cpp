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
	UE_LOG(LogTemp, Warning, TEXT("SHOT FIRED!"));
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));
	
	AController* OwnerController = Cast<APawn>(GetOwner())->GetController();
	if(!OwnerController) { return; }

	FVector ViewpointLocation;
	FRotator ViewpointRotation;
	
	OwnerController->GetPlayerViewPoint(ViewpointLocation, ViewpointRotation);

	DrawDebugCamera(GetWorld(), ViewpointLocation, ViewpointRotation, 90, 2, FColor::Red, true);
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