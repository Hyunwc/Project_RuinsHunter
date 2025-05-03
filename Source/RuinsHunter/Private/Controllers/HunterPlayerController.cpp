// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/HunterPlayerController.h"

AHunterPlayerController::AHunterPlayerController()
{
	PlayerTeamId = FGenericTeamId(0);
}

FGenericTeamId AHunterPlayerController::GetGenericTeamId() const
{
	return PlayerTeamId;
}
