// Fill out your copyright notice in the Description page of Project Settings.
/*
This file is a draft/helper for a UDP Communication class to be used with Unreal Engine.
The class name follows Unreal Engine coding standards:
"(...)Most other classes are prefixed by F, though some subsystems use other letters."
available at https://docs.unrealengine.com/latest/INT/Programming/Development/CodingStandard/
Author: Bruno Matos, based on example from http://www.binarytides.com/udp-socket-programming-in-winsock/
and Windows documentation on Winsock2
*/
#pragma once

#undef UNICODE

#define WIN32_LEAN_AND_MEAN

//#include "CoreMinimal.h"
/*#include "AllowWindowsPlatformTypes.h"		// Unreal does not like
#include <winsock2.h>						// winsock2.h nor
#include <windows.h>						// windows.h
#include "HideWindowsPlatformTypes.h"*/		// so we need to surround them with Allow- and HideWindowsPlatformTypes.h
#include "Networking.h"
#include "Net/NetworkProfiler.h"
#include "Runtime/Sockets/Public/Sockets.h"
//#include "Runtime/Sockets/Private/Sockets.cpp"
#include "Runtime/Sockets/Public/SocketSubsystem.h"
#include "Engine.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>

#pragma comment(lib,"ws2_32.lib")			// link to Winsock Library


//enum class ESocketType { SERVER, CLIENT };	// use this if you need it


/**
 * 
 */
class BATTERYCOLLECTOR_API FUDPCommunication
{
public:
	
	FUDPCommunication(FString& serverAddress, int32 portNumber);//, ESocketType socketType);
	~FUDPCommunication();

	/*bool sendMessage(FString Message);
	FString GrabWaitingMessage();
	static FString StringFromBinaryArray(const TArray<uint8>&  BinaryArray);*/


	// Holds the socket we are sending on
	FSocket* Socket;
	TSharedPtr<FInternetAddr> InternetAddress;
	int32 port = 60000;
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
