// Fill out your copyright notice in the Description page of Project Settings.
/*
This file is a draft/helper for a UDP Communication class to be used with Unreal Engine.
The class name follows Unreal Engine coding standards:
"(...)Most other classes are prefixed by F, though some subsystems use other letters."
available at https://docs.unrealengine.com/latest/INT/Programming/Development/CodingStandard/
Author: Bruno Matos, based on example from http://www.binarytides.com/udp-socket-programming-in-winsock/
and Windows documentation on Winsock2
*/
#define WIN32_LEAN_AND_MEAN

#include "UDPCommunication.h"					// Unreal demands the relative .h file relative
// 		to the current .cpp file to be the first #include statement
#include "AllowWindowsPlatformTypes.h"			// Unreal does not like
#include <winsock2.h>							// 		winsock2.h nor
#include <windows.h>							// 		windows.h
#include "HideWindowsPlatformTypes.h"			// 		so we need to surround them with Allow- and HideWindowsPlatformTypes.h
//#include "Runtime/Sockets/Private/Sockets.cpp"
#include <stdio.h>

#pragma comment(lib,"ws2_32.lib")				// link to Winsock Library

#define BUFLEN 512  // Max length of buffer


FUDPCommunication::FUDPCommunication(FString& serverAddress, int32 portNumber)//, ESocketType socketType)
{
	serverAddress = address;
	portNumber = port;
	Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_DGram, TEXT("MySocket"), true);
	Socket->SetNonBlocking(true);
	Socket->SetBroadcast(true);
	Socket->SetReuseAddr(true);
	
	UE_LOG(LogTemp, Warning, TEXT("Socket created(?)"));

	FIPv4Address::Parse(address, ip);

	InternetAddress = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();

	InternetAddress->SetIp(ip.Value);
	InternetAddress->SetPort(port);
	
	binded = Socket->Bind(*InternetAddress);
	if (binded == true)
	{
		UE_LOG(LogTemp, Warning, TEXT("Binded: true"));
	}

	FString message = ("Hello");
	TCHAR *serializedMessage = message.GetCharArray().GetData();
	int32 size = FCString::Strlen(serializedMessage);
	int32 sent = 0;

	sent = Socket->SendTo((uint8*)TCHAR_TO_UTF8(serializedMessage), size, sent, *InternetAddress);

	if (sent && sent > 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Message sent"));
	}

	uint32 Size;
	TSharedRef<FInternetAddr> targetAddress = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	while(Socket->HasPendingData(Size))
	{
		int32 Read;
		TArray<uint8> ReceivedData;
		received = Socket->RecvFrom(ReceivedData.GetData(), ReceivedData.Num(), Read, *targetAddress);	
		if (received == true)
		{
			UE_LOG(LogTemp, Warning, TEXT("Message Received"));
		}
	}

}

FUDPCommunication::~FUDPCommunication()
{
	ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(Socket);
	//Socket = nullptr;
}

/*bool FUDPCommunication::Init()
{
	return true;
}

uint32 FUDPCommunication::Run()
{

}*/