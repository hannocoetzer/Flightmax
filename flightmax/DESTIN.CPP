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

#include "box.h"
#include "destin.h"
#include <stdlib.h>
#include <iostream.h>
#include <conio.h>
#include <string.h>

/*------------------------Destination Input----------------------------*/

void destination::destinput()
{
	char temp[30];
	aeroinput();
	dist=atof(strcpy(temp,validate(28,11,6,2,3,40000,"Must be less than 40000")));
	cost=atof(strcpy(temp,validate(28,13,7,2,2,30000,"Must be less than 30000")));
	booked=atoi(strcpy(temp,validate(65,13,4,0,4,999,"Must be less than 1000")));



}

/*-------------------------Destination display-------------------------*/

void destination::destdisplay()
{
	aerodisplay();
	box dest;
	dest.smallbar(8,28,11);
	gotoxy(3,11);
	cout<<"Trip distance       :    "<<dist;
	dest.smallbar(9,28,13);
	gotoxy(3,13);
	cout<<"Cost per trip       :    "<<cost;
	dest.smallbar(4,65,13);
	gotoxy(40,13);
	cout<<"Total seats booked  :    "<<booked;


}