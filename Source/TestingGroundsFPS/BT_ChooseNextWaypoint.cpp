// Fill out your copyright notice in the Description page of Project Settings.

#include "BT_ChooseNextWaypoint.h"





EBTNodeResult::Type UBT_ChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UE_LOG(LogTemp, Warning, TEXT("It's AI Bitch"));
	return EBTNodeResult::Succeeded;
}