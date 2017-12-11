// Fill out your copyright notice in the Description page of Project Settings.

#include "Multiplayer.h"
#include "AllowWindowsPlatformTypes.h"
#include <thread>
#include <queue>
#include "HideWindowsPlatformTypes.h"		
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>



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


	connectionObj.Connection(address, port);
	
	/*std::thread t (connectionObj.receiveMessage);
	std::queue<int> q;
	

	for (int i = 0; i < 6; i++)
	{
		
	}*/
}
	
// Called every frame
void AMultiplayer::Tick(float DeltaTime)
{
	FString message = TEXT("Hello");;

	connectionObj.sendMessage(message);
	connectionObj.receiveMessage();
	//FString message = TEXT("Helloo");;
	//FUDPCommunication messageObj;

	//messageObj.sendMessage(message);
	//messageObj.receiveMessage();
}



