// Copyright Epic Games, Inc. All Rights Reserved.

#include "ActionGASGameMode.h"
#include "ActionGASCharacter.h"
#include "UObject/ConstructorHelpers.h"

AActionGASGameMode::AActionGASGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
