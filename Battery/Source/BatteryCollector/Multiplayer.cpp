// Fill out your copyright notice in the Description page of Project Settings.

#include "Multiplayer.h"
#include "UDPCommunication.h"


// Sets default values
AMultiplayer::AMultiplayer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMultiplayer::BeginPlay()
{
	Super::BeginPlay();

	int32 port = 50000;
	FString address = "127.0.0.1";



	FUDPCommunication connectionObj;
	connectionObj.Connection(address, port);
	UE_LOG(LogTemp, Warning, TEXT("wtf"));
}
	
// Called every frame
void AMultiplayer::Tick(float DeltaTime)
{
	//FString message = TEXT("Helloo");;
	//FUDPCommunication messageObj;

	//messageObj.sendMessage(message);
	//messageObj.receiveMessage();
}



