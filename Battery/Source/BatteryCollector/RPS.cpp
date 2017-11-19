// Fill out your copyright notice in the Description page of Project Settings.

#include "RPS.h"




bool RPSWin(int OtherTeam, int YourTeam, int Range)
{
	int Middle = Range >> 1;//find the middle
	YourTeam %= Range;//put your data in range
	OtherTeam %= Range;//put other team data in range
	int swift = Middle - OtherTeam;//find the velocity 
	Yourteam = (Yourteam + swift)%Range;
	return(YourTeam<Middle)
}