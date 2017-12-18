// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UDPCommunication.h"
#include "SendCharacterMovement.generated.h"

UENUM(BlueprintType)
enum class casesEnum : uint8
{
	mvf 	UMETA(DisplayName = "mvf"),
	mvr 	UMETA(DisplayName = "mvr")
};
UCLASS()
class BATTERYCOLLECTOR_API USendCharacterMovement : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	FUDPCommunication object;
	FString message;
	/*enum cases {
		MoveForward,
		MoveRight
	};*/
	
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
		casesEnum cases;*/
	
	UFUNCTION(BlueprintCallable, Category = "Communication")
		FString SendComm(int32 id, casesEnum cases, FString data);

	
	
	UFUNCTION(BlueprintCallable, Category = "Communication")
		bool ReceiveCommunication();
};
