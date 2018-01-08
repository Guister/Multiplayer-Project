

#include "UDPCommunication.h"	
#include <stdio.h>

#define BUFLEN 512  // Max length of buffer

FUDPCommunication::FUDPCommunication()
{
}

bool FUDPCommunication::Connection(FString& serverAddress, int32 portNumber)//, ESocketType socketType)
{
	GConfig->GetString(TEXT("/Script/Engine.Network"), TEXT("address"), address, GGameIni);
	GConfig->GetInt(TEXT("/Script/Engine.Network"), TEXT("port"), port, GGameIni);
	serverAddress = address;
	portNumber = port;

	Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_DGram, TEXT("MySocket"), true);
	Socket->SetNonBlocking(true);
	Socket->SetBroadcast(true);
	Socket->SetReuseAddr(true);
	//Socket->SetRecvErr(true);

	UE_LOG(LogTemp, Warning, TEXT("Socket created(?)"));

	FIPv4Address::Parse(address, ip);

	InternetAddress = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();

	InternetAddress->SetIp(ip.Value);
	InternetAddress->SetPort(port);

	binded = Socket->Bind(*InternetAddress);
	if (binded == true)
	{
		UE_LOG(LogTemp, Warning, TEXT("Binded: true"));
		return true;
	}
	else
	{
		return false;
	}
}
bool FUDPCommunication::sendMessage(FString Message)
{
	//FString message = TEXT("Hello");
	//FTimespan waitTime = FTimespan(10);
	TCHAR *serializedMessage = Message.GetCharArray().GetData();
	int32 size = FCString::Strlen(serializedMessage);
	int32 Sent = 0;

	sent = Socket->SendTo((uint8*)TCHAR_TO_UTF8(serializedMessage), size, Sent, *InternetAddress);
	if (sent == true && Sent > 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Message sent"));
		return true;
	}
	else
	{
		return false;
	}
}
FString FUDPCommunication::receiveMessage()
{
	uint32 Size;
	TArray<uint8> ReceivedData;
	TSharedRef<FInternetAddr> targetAddress = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	if (Socket->HasPendingData(Size) == true)
	{
		UE_LOG(LogTemp, Warning, TEXT("Has data to receive"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No data"));
	}
	while (Socket->HasPendingData(Size))
	{
		ReceivedData.SetNumUninitialized(FMath::Min(Size, 65507u));
		int32 Read;
		received = Socket->RecvFrom(ReceivedData.GetData(), ReceivedData.Num(), Read, *targetAddress);
		if (received == true)
		{
			UE_LOG(LogTemp, Warning, TEXT("Message Received"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Message was not received"));
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Data Read! %d"), ReceivedData.Num()));
	//return StringFromBinaryArray(ReceivedData);

	FString data;
	const std::string cstr(reinterpret_cast<const char*>(ReceivedData.GetData()), ReceivedData.Num());
	data += FString(cstr.c_str());
	UE_LOG(LogTemp, Warning, TEXT("message:%s"), *data);
	return data;
}

/*
FString FUDPCommunication::StringFromBinaryArray(const TArray<uint8>&  BinaryArray)
{
	//FString data;
	const std::string cstr(reinterpret_cast<const char*>(BinaryArray.GetData()), BinaryArray.Num());
	//data += FString(cstr.c_str());
	UE_LOG(LogTemp, Warning, TEXT("message:%s"), FString(cstr.c_str()));
	return FString(cstr.c_str());
	
}
*/




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