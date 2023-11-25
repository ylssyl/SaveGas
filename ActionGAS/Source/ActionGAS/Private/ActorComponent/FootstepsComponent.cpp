// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorComponent/FootstepsComponent.h"

#include "ActionGAS\ActionGASCharacter.h"
#include "CollisionQueryParams.h"
#include "PhysicalMaterials/AG_PhysicalMaterial.h"
#include "Kismet/GameplayStatics.h"

static TAutoConsoleVariable<int32> CVarShowFootsteps(
	TEXT("ShowFootsteps"),
	0,
	TEXT("Draw Debug info about Footsteps/n		0:off/n		1:on/n"),
	ECVF_Cheat
);

// Sets default values for this component's properties
UFootstepsComponent::UFootstepsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFootstepsComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UFootstepsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UFootstepsComponent::HandleFootStep(EFoot foot)
{
	if (AActionGASCharacter* Character = Cast<AActionGASCharacter>(GetOwner()))
	{
		int32 DebugShowFootsteps = CVarShowFootsteps.GetValueOnAnyThread();

		if (USkeletalMeshComponent* Mesh = Character->GetMesh())
		{
			FVector SocketLocation = Mesh->GetSocketLocation(foot == EFoot::F_Left ? LeftFootSocketName : RightFootSocketName);
			FHitResult HitResult;
			FVector Location = SocketLocation + FVector::UpVector * 20;

			FCollisionQueryParams QueryParams;
			QueryParams.bReturnPhysicalMaterial = true;
			QueryParams.AddIgnoredActor(Character);

			if (GetWorld()->LineTraceSingleByChannel(HitResult, Location, Location + FVector::UpVector * -50.f, ECollisionChannel::ECC_WorldStatic, QueryParams))
			{
				if (HitResult.bBlockingHit)
				{
					if (HitResult.PhysMaterial.Get())
					{
						UAG_PhysicalMaterial* PhysicalMaterial = Cast<UAG_PhysicalMaterial>(HitResult.PhysMaterial.Get());

						if (PhysicalMaterial)
						{
							UGameplayStatics::PlaySoundAtLocation(this, PhysicalMaterial->FootstepSound, Location, 0.1f,  1.f);

							if (DebugShowFootsteps > 0)
							{
								DrawDebugString(GetWorld(), Location, PhysicalMaterial->GetName(), nullptr, FColor::White, 4.f);
							}
						}

						if (DebugShowFootsteps > 0)
						{
							DrawDebugSphere(GetWorld(), Location, 16, 16, FColor::Red, false, 4.f);
						}
					}
					else
					{
						if (DebugShowFootsteps > 0)
						{
							DrawDebugLine(GetWorld(), Location, Location + FVector::UpVector * -50.f, FColor::Red, false,  4.f, 0,  1);
						}
					}
				}
				else
				{
					if (DebugShowFootsteps > 0)
					{
						DrawDebugLine(GetWorld(), Location, Location + FVector::UpVector * -50.f, FColor::Red, false, 4.f, 0, 1);
						DrawDebugSphere(GetWorld(), Location, 16, 16, FColor::Red, false, 4.f);
					}
				}
			}
		}
	}
}