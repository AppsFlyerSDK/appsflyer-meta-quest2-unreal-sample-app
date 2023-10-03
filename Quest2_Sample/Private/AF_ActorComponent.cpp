// Fill out your copyright notice in the Description page of Project Settings.


#include "AF_ActorComponent.h"
#include "../AppsflyerQuest2Module/AppsflyerQuest2Module.h"

// Sets default values for this component's properties
UAF_ActorComponent::UAF_ActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAF_ActorComponent::BeginPlay()
{
	Super::BeginPlay();
	AppsflyerQuest2Module()->Init(<< DEV_KEY >>, << PACKAGE_NAME >>);
	// af send firstopen/session
	AppsflyerPCModule()->SetCustomerUserId("cuid-test");
	AppsflyerPCModule()->Start();
	// AppsflyerPCModule()->Stop();
	//set event name
	std::string event_name = "af_purchase";
	//set json string
	std::string event_parameters = "{\"af_currency\":\"USD\",\"af_price\":6.66,\"af_revenue\":24.12}";
	// af send inapp event
	AppsflyerPCModule()->LogEvent(event_name, event_parameters);
	// ...
	
}


// Called every frame
void UAF_ActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

