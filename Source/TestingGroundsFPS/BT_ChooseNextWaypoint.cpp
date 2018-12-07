// Fill out your copyright notice in the Description page of Project Settings.

#include "BT_ChooseNextWaypoint.h"
#include "AIController.h"
#include "PatrolRouteComponent.h"
#include "BehaviorTree/BlackboardComponent.h"





EBTNodeResult::Type UBT_ChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{



	//Get the Patrol route
	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto CNWPatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRouteComponent>();

	if (!ensure(CNWPatrolRoute)) { return EBTNodeResult::Failed; }

	
	auto PatrolPoints = CNWPatrolRoute->GetPatrolPoints();
	if (PatrolPoints.Num() == 0)
	{
		UE_LOG (LogTemp, Warning, TEXT("No Patrol Points Found"))
		
			return EBTNodeResult::Failed;

	}

	//Set Next Waypoint
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);
	UE_LOG(LogTemp, Warning, TEXT("Waypoint Index: %i"), Index);

	//Cycle Index
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
	
	return EBTNodeResult::Succeeded;
}