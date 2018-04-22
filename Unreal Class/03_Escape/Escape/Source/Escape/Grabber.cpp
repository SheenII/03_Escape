// Copyright 2018 Andrew Sheen


#include "Grabber.h"
#include "Engine/World.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DrawDebugHelpers.h"

//This is defining our own Macro. 
#define OUT


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Grabber reporting for duty"));

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	///Get platyer viewpoint this click
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation	
	);
		
	///Log out to test	
	
	
	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach; 

	///Draw a red line in the world tovisualise the player reach
	DrawDebugLine(
		GetWorld(),
		PlayerViewPointLocation,
		LineTraceEnd,
		FColor(255, 0, 0),
		false,
		0.f,
		0.f,
		10.f
	);
	///Setup query parameters
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

	///Line Trace (Ray-cast out to reach distance)
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
	);

	///See what we hit
	AActor* ActorHit = Hit.GetActor();
	if (ActorHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("Line trace hit: %s"), *(ActorHit->GetName()))
	}
	/*Pointers and references.
	pointers and References both point to something that is stored.
	Pointers dan be reassigned to another address but a Reference is going to always belong
	to the address initially assigned. A reference is fikxed. A pointer can be "null" but
	a reference cannnot. A reference muyst be initialised, since it cannot be reassigned 
	making it "null" will always mean it is nothing. To access a pointer you need to put
	a "*" infront of it - *ActorPtr - because a pointer basically hides the object it is
	pointing to. A reference is basically pretending to be the object and there will be
	no need for special coding to make it happen. To access an address you won't need 
	anything to help the pointer but the reference needs the ampersand (&). To change the 
	of the pointer you need to basically code it like this ActorPtr = &Actor. The reference 
	is not allowed to change addresses so no coding is available. Changing the value...
	The pointer is done like this *ActorPtr = Actor. The reference is similar but without 
	the asterisk like this ActorPtr = Actor.
	*****Pointers are more powerful but also dangerous. Use references unless you can't.

	*/
}

