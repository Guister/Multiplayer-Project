// Fill out your copyright notice in the Description page of Project Settings.

#include "SendCharacterMovement.h"



FString USendCharacterMovement::SendComm(int32 id, casesEnum cases, FString data)
{
	
	FString actionString;
	FString idString;
	FString finalMessage;

		switch (cases)
		{
		case casesEnum::mvf:
			actionString = TEXT("mvf");

			break;

		case casesEnum::mvr:
			actionString = TEXT("mvr");

			break;
		}


		idString = FString::FromInt(id);

		/*finalMessage = idString;
		finalMessage += actionString;
		finalMessage += data;*/

		finalMessage.Append(idString).Append(actionString).Append(data);
		
		object.sendMessage(finalMessage);

		return finalMessage;
		
}

bool USendCharacterMovement::ReceiveCommunication()
{

	FString originalString;
	std::string exampleID;
	std::string exampleAction;
	std::string exampleData;

	originalString = object.receiveMessage();

	std::string originalstringSTD(TCHAR_TO_UTF8(*originalString));

	exampleID = originalstringSTD.substr(0, 2);
	exampleAction = originalstringSTD.substr(2, 3);
	exampleData = originalstringSTD.substr(5, 1);

	FString ID(exampleID.c_str());
	FString Action(exampleAction.c_str());
	FString Data(exampleData.c_str());
	
	
	return false;
}

void USendCharacterMovement::a()
{}
