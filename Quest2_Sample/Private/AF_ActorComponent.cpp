// Fill out your copyright notice in the Description page of Project Settings.


#include "AF_ActorComponent.h"
#include "../AppsflyerPCModule/AppsflyerQuest2Module.h"

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

	// af module init
	AppsflyerQuest2Module()->Init(<< DEV_KEY >> , << PACKAGE_NAME >> );

	// af send firstopen/session
	AppsflyerQuest2Module()->Start();

	// set event name
	std::string event_name = "af_purchase";
	// set json string
	std::string event_parameters = "{\"af_currency\":\"USD\",\"af_price\":6.66,\"af_revenue\":24.12}";
	// af send inapp event
	AppsflyerQuest2Module()->LogEvent(event_name, event_parameters);

	// set non-English values for testing UTF-8 support
	std::wstring ws = L"車B1234 こんにちは";
	std::wstring ws2 = L"新人邀约购物日";
	std::string event_custom_parameters = "{\"goodsName\":\"" + AppsflyerQuest2Module()->to_utf8(ws) + "\",\"goodsName2\":\"" + AppsflyerQuest2Module()->to_utf8(ws2) + "\"}";
	// af send inapp event with custom params
	AppsflyerQuest2Module()->LogEvent(event_name, event_parameters, event_custom_parameters);

	// stop the SDK
	AppsflyerQuest2Module()->Stop();
	
}


// Called every frame
void UAF_ActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

