// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArchVisCharacter.h"
#include "PatrollingGuard.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDSFPS_API APatrollingGuard : public AArchVisCharacter
{
	GENERATED_BODY()

public:
	UPROPERTY (EditInstanceOnly, Category = "Patrol Route")
		TArray<AActor*> PatrolPointsCPP;
	
};
