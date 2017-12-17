// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UDPCommunication.h"
#include "SendCharacterMovement.generated.h"

/**
 * 
 */
UCLASS()
class BATTERYCOLLECTOR_API USendCharacterMovement : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		FUDPCommunication object;
	FString message;
	enum cases {
		MoveForward,
		MoveRight
	};

	/*
	UFUNCTION(BlueprintCallable, Category = "Communication")
		FString Comm(int32 id, enum cases, FString data);*/
	
};
