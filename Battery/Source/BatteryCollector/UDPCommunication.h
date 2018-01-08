
#pragma once

#undef UNICODE

#define WIN32_LEAN_AND_MEAN


#include "Networking.h"
#include "Net/NetworkProfiler.h"
#include "Runtime/Sockets/Public/Sockets.h"
//#include "Runtime/Sockets/Private/Sockets.cpp"
#include "Runtime/Sockets/Public/SocketSubsystem.h"
#include "Engine.h"
#include "ConfigCacheIni.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>


/**
 * 
 */
class BATTERYCOLLECTOR_API FUDPCommunication
{
public:
	
	FUDPCommunication();//, ESocketType socketType);
	~FUDPCommunication();

	UFUNCTION(BlueprintCallable, Category = "Sockets")
	bool Connection(FString& serverAddress, int32 portNumber);

	UFUNCTION(BlueprintCallable, Category = "Sockets")
	bool sendMessage(FString Message);

	UFUNCTION(BlueprintCallable, Category = "Sockets")
	FString receiveMessage();

	//static FString StringFromBinaryArray(const TArray<uint8>&  BinaryArray);
	

	// Holds the socket we are sending on
	FSocket* Socket;
	TSharedPtr<FInternetAddr> InternetAddress;
	int32 port = 50000;
	FString address = "127.0.0.1";
	// Description for debugging
	FString SocketDescription;
	bool connected;
	bool binded;
	bool listening;
	bool sent;
	bool received;

public:
/*
	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Stop() override;
	*/
private:
	

	
	
	// Remote Address
	FIPv4Endpoint RemoteEndPoint; //talvez
	FIPv4Address ip;

	// Socket Subsystem
	ISocketSubsystem* SocketSubsystem;

	//UDPReceiveWorker* myRecieverWorker;
	// The data
	TArray<uint8> ReceivedData;


};
