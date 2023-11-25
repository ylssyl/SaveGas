// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotifies/AnimNotify_Step.h"
#include "ActionGAS\ActionGASCharacter.h"
#include "ActorComponent/FootstepsComponent.h"

void UAnimNotify_Step::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	AActionGASCharacter* Character = MeshComp ? Cast<AActionGASCharacter>(MeshComp->GetOwner()) : nullptr;

	if (Character)
	{
		if (UFootstepsComponent* FootStepsComponent = Character->GetFootstepsComponent())
		{
			FootStepsComponent->HandleFootStep(Foot);
		}
	}
}