// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TP_TopDown/TP_TopDownPlayerController.h"
#include "Runtime/Core/Public/HAL/Runnable.h"
#include "Runtime/Core/Public/HAL/RunnableThread.h"

/**
 * 
 */
class BATTERYCOLLECTOR_API FPrimeNumberWorker : public FRunnable
{
	/** Singleton instance, can access the thread any time via static accessor, if it is active! */
	static  FPrimeNumberWorker* Runnable;

	/** Thread to run the worker FRunnable on */
	FRunnableThread* Thread;

	/** The Data Ptr */
	TArray<uint32>* PrimeNumbers;

	/** The PC */
	ATP_TopDownPlayerController* ThePC;

	/** Stop this thread? Uses Thread Safe Counter */
	FThreadSafeCounter StopTaskCounter;

	//The actual finding of prime numbers
	int32 FindNextPrimeNumber();

private:
	int32				PrimesFoundCount;
public:

	int32				TotalPrimesToFind;

	//Done?
	bool IsFinished() const
	{
		return PrimesFoundCount >= TotalPrimesToFind;
	}

	//~~~ Thread Core Functions ~~~

	//Constructor / Destructor
	FPrimeNumberWorker(TArray<uint32>& TheArray, const int32 IN_PrimesToFindPerTick, ATP_TopDownPlayerController* IN_PC);
	virtual ~FPrimeNumberWorker();

	// Begin FRunnable interface.
	virtual bool Init();
	virtual uint32 Run();
	virtual void Stop();
	// End FRunnable interface

	/** Makes sure this thread has stopped properly */
	void EnsureCompletion();



	//~~~ Starting and Stopping Thread ~~~



	/*
	Start the thread and the worker from static (easy access)!
	This code ensures only 1 Prime Number thread will be able to run at a time.
	This function returns a handle to the newly started instance.
	*/
	static FPrimeNumberWorker* JoyInit(TArray<uint32>& TheArray, const int32 IN_TotalPrimesToFind, ATP_TopDownPlayerController* IN_PC);

	/** Shuts down the thread. Static so it can easily be called from outside the thread context */
	static void Shutdown();

	static bool IsThreadFinished();

};