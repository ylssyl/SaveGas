// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/AG_AnimInstance.h"

#include "ActionGAS/ActionGASCharacter.h"
#include "ActionGAS/ActionGameTypes.h"
#include "Animation/BlendSpace.h"
#include "Animation/AnimationAsset.h"
#include "Animation/AnimSequenceBase.h"
#include "DataAssets/CharacterAnimDataAsset.h"
#include "DataAssets/CharacterDataAsset.h"


UBlendSpace* UAG_AnimInstance::GetLocomotionBlendspace() const
{
	if (AActionGASCharacter* ActionGASCharacter = Cast<AActionGASCharacter>(GetOwningActor()))
	{
		FCharacterData Data = ActionGASCharacter->GetCharacterData();

		if (Data.CharacterAnimDataAsset)
		{
			return Data.CharacterAnimDataAsset->CharacterAnimationData.MovementBlendSpace;
		}
	}
	return DefaultCharacterAnimDataAsset ? DefaultCharacterAnimDataAsset->CharacterAnimationData.MovementBlendSpace : nullptr;
}

UAnimSequenceBase* UAG_AnimInstance::GetIdleAnimation() const
{
	if (AActionGASCharacter* ActionGASCharacter = Cast<AActionGASCharacter>(GetOwningActor()))
	{
		FCharacterData Data = ActionGASCharacter->GetCharacterData();

		if (Data.CharacterAnimDataAsset)
		{
			return Data.CharacterAnimDataAsset->CharacterAnimationData.IdleAnimationAsset;
		}
	}
	return DefaultCharacterAnimDataAsset ? DefaultCharacterAnimDataAsset->CharacterAnimationData.IdleAnimationAsset : nullptr;
}

UBlendSpace* UAG_AnimInstance::GetCrouchLocomotionBlendspace() const
{
	if (AActionGASCharacter* ActionGASCharacter = Cast<AActionGASCharacter>(GetOwningActor()))
	{
		FCharacterData Data = ActionGASCharacter->GetCharacterData();

		if (Data.CharacterAnimDataAsset)
		{
			return Data.CharacterAnimDataAsset->CharacterAnimationData.CrouchMovementBlendSpace;
		}
	}
	return DefaultCharacterAnimDataAsset ? DefaultCharacterAnimDataAsset->CharacterAnimationData.CrouchMovementBlendSpace : nullptr;
}

UAnimSequenceBase* UAG_AnimInstance::CrouchGetIdleAnimation() const
{
	if (AActionGASCharacter* ActionGASCharacter = Cast<AActionGASCharacter>(GetOwningActor()))
	{
		FCharacterData Data = ActionGASCharacter->GetCharacterData();

		if (Data.CharacterAnimDataAsset)
		{
			return Data.CharacterAnimDataAsset->CharacterAnimationData.CrouchIdleAnimationAsset;
		}
	}
	return DefaultCharacterAnimDataAsset ? DefaultCharacterAnimDataAsset->CharacterAnimationData.CrouchIdleAnimationAsset : nullptr;
}

UAnimSequenceBase* UAG_AnimInstance::GetSequenceBase() const
{
	if (AActionGASCharacter* ActionGASCharacter = Cast<AActionGASCharacter>(GetOwningActor()))
	{
		FCharacterData Data = ActionGASCharacter->GetCharacterData();

		if (Data.CharacterAnimDataAsset)
		{
			return Data.CharacterAnimDataAsset->CharacterAnimationData.SequenceBase;
		}
	}
	return DefaultCharacterAnimDataAsset ? DefaultCharacterAnimDataAsset->CharacterAnimationData.SequenceBase : nullptr;
}