// Copyright 2018 Andrew Sheen

/* includes in current UE are used when needed.
they call it declare what you use */
#include "Grabber.h"
#include "Engine/World.h"
#include "Engine/EngineTypes.h"
#include "CoreMinimal.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Components/ActorComponent.h"
#include "DrawDebugHelpers.h"

//This is defining our own Macro. 
#define OUT
/// When do we use :: or , or ->
/// If the left hand term is a Class, Enum or Namspace then you us ::. These will be items
/// stored in permanenet storage.
/// If the left hand item is a Pointer then you will use the ->. 
/// If the left hand item is an Instance or a Reference then you use the . .
/// The last two items will or might vary at runtime. These are differnet than
/// uing the :: since this is a known item in memory.

/* A Hot Loop is code that gets called often. We want and need to be able to know what code is called alot.
TickComponent is a good example. It get's called everyframe.*/

/// Sets default values for this component's properties
/*Scope resolution operator (::) in C++ programming language is used to define a function outside a class
or when we want to use a global variable but also has a local variable with the same name. */
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	FindPhysicsHandleComponent();
	SetupInputComponent();	
}
/// Look for attached physics handle
void UGrabber::FindPhysicsHandleComponent()
{	
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("PhysicsHandle component not attached to %s"), *GetOwner()->GetName())
	}

}
/// Look for attached Input Components (only appears at runtime)
void UGrabber::SetupInputComponent()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s is missing input component"), *GetOwner()->GetName())
	}
}

void UGrabber::Grab()
{
	// LINE TRACE and see if we reach any actors with physics body collision set
	auto HitResult = GetFirstphysicsBodyInReach();
	auto ComponentToGrab = HitResult.GetComponent();
	auto ActorHit = HitResult.GetActor();
	// If we hit something then attach a physics handle
	if (ActorHit)
	{
		PhysicsHandle->GrabComponentAtLocationWithRotation(
			ComponentToGrab,
			NAME_None,
			ComponentToGrab->GetOwner()->GetActorLocation(),
			ComponentToGrab->GetOwner()->GetActorRotation()
		);
	}
}

void UGrabber::Release()
{	
	PhysicsHandle->ReleaseComponent();
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// If the physics handle is attached
	if (PhysicsHandle->GrabbedComponent)		
		{
		// Move the object that we are holding each frame
		PhysicsHandle->SetTargetLocation(GetReachLineEnd());
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

const FHitResult UGrabber::GetFirstphysicsBodyInReach()
{
	///Line Trace (Ray-cast out to reach distance)
	FHitResult HitResult;
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
	GetWorld()->LineTraceSingleByObjectType(
		OUT HitResult,
		GetReachLineStart(),
		GetReachLineEnd(),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
	);
	return HitResult;
}

FVector UGrabber::GetReachLineStart()
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);
	return PlayerViewPointLocation;
}

FVector UGrabber::GetReachLineEnd()
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);
	return PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;
}
/* Red Green Refactor. 
Red = not working
Green = Working but could use some cleaning up of the code
Refactor = The clean up
*/