// Fill out your copyright notice in the Description page of Project Settings.

#include "RPS.h"




bool URPS::RPSWin(int32 OtherTeam, int32 YourTeam, int32 Range)
{
	int32 Middle = Range >> 1;//find the middle
	YourTeam %= Range;//put your data in range
	OtherTeam %= Range;//put other team data in range
	int32 swift = Middle - OtherTeam;//find the velocity 
	YourTeam = (YourTeam + swift)%Range;
	return(YourTeam < Middle);
}


/*

M[0:2];
bool message(Fstring data, enum blabla) {
	char message;
	switch blabla
		case moveforward:
			message += 'MFA';
			break;


	message += data
}*/