/*-------------------------------------------------------------------------
Filename         :Proj6b
Author           :JDJ Coetzer
Created          :2001/07/20
Operating System :Ms-Dos

Description:
This program has been written to input flight details for a small airline
company,write it to a file for future reference


Modification:
Some bug fixes with file handling and a new menu system

----------------------------------------------------------------------------*/

#include "input.h"
#include "box.h"
#include "aero.h"
#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

/*----------------------Aeroplane Input function---------------------*/

void aeroplane::aeroinput()
{
	char temp[30];
	box aero;
	gotoxy(3,5);
	cout<<"Aeroplane Type      : ";
	aero.smallbar(20,28,5);
	gotoxy(3,7);
	cout<<"Aeroplane Number    : ";
	aero.smallbar(5,28,7);
	gotoxy(35,7);
	cout<<"Aeroplane Fuel Consumption  :       l/100km";
	aero.smallbar(6,65,7);
	gotoxy(3,11);
	cout<<"Trip distance       : ";
	aero.smallbar(8,28,11);
	gotoxy(3,13);
	cout<<"Cost per trip       : ";
	aero.smallbar(9,28,13);
	gotoxy(40,13);
	cout<<"Total seats booked   : ";
	aero.smallbar(4,65,13);
	gotoxy(20,17);
	cout<<"Total pilots onboard       : ";
	aero.smallbar(3,50,17);
	gotoxy(20,19);
	cout<<"Total attendants onboard   : ";
	aero.smallbar(3,50,19);
	strcpy(type,validate(28,5,18,1,6,0,""));
	num=atoi(strcpy(temp,validate(28,7,5,0,5,9999,"Must be less than 10000")));
	csumpt=atof(strcpy(temp,validate(65,7,4,2,3,99,"Must be less than 100")));


}

/*----------------------------Aeroplane display-------------------------*/

void aeroplane::aerodisplay()
{
	box aero;
	aero.smallbar(20,28,5);
	gotoxy(3,5);
	cout<<"Aeroplane Type      :    "<<type;
	aero.smallbar(5,28,7);
	gotoxy(3,7);
	cout<<"Aeroplane Number    :    "<<num;
	aero.smallbar(6,65,7);
	gotoxy(35,7);
	cout<<"Aeroplane Fuel Consumption  : "<<csumpt;
	gotoxy(70,7);
	cout<<" l/100km";

}