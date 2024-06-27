#include "Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"

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
	UE_LOG(LogTemp, Warning, TEXT("SHOOT!"));
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));
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