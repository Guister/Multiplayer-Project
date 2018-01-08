// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SendCharacterMovement.h"
#include "BlueprintAccess.generated.h"

/**
 * 
 */
UCLASS()
class BATTERYCOLLECTOR_API UBlueprintAccess : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	static USendCharacterMovement object;
	static int32 id;
	static casesEnum cases;
	static FString data;

	UFUNCTION(BlueprintCallable, Category = "Communication")
		static void senda();

	
	
};
