// Fill out your copyright notice in the Description page of Project Settings.

#include "SendCharacterMovement.h"



FString USendCharacterMovement::SendComm(int32 id, casesEnum cases, FString data)
{
	//int number;
	FString actionString;
	FString idString;
	FString finalMessage;


	//while (number >= MoveForward && number <= MoveRight)
	//{ 
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
		
	//}
}

bool USendCharacterMovement::ReceiveCommunication()
{

	FString originalString;
	FString exampleID;
	FString exampleAction;
	FString exampleData;

	originalString = object.receiveMessage();

	exampleID = originalString.Left(2);
	exampleAction = originalString.Mid(2, 3);
	exampleData = originalString.Right(1);

	
	
	
	
	return false;
}


