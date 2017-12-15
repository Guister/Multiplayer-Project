// Fill out your copyright notice in the Description page of Project Settings.

#include "SendCharacterMovement.h"


FString USendCharacterMovement::Comm(int32 id, cases action, FString data)
{
	int number;
	FString actionString;
	FString idString;
	FString finalMessage;


	while (number >= MoveForward && number <= MoveRight)
	{ 
		switch (number)
		{
		case MoveForward:
			actionString = TEXT("MoveForward");

			break;

		case MoveRight:
			actionString = TEXT("MoveRight");

			break;
		}


		idString = FString::FromInt(id);
		
		//object.sendMessage();
			
			
		

		
	}
}


