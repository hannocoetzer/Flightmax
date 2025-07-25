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
#include "crew.h"
#include <stdlib.h>
#include <iostream.h>
#include <conio.h>

/*---------------------------Crew Input----------------------------------*/

void crew::crewinput()
{
	char temp[30];
	pilots=atoi(strcpy(temp,validate(50,17,3,0,5,7,"Must be less than 8")));
	attends=atoi(strcpy(temp,validate(50,19,3,0,5,24,"Must be less than 25")));


}

/*---------------------------Crew Display--------------------------------*/

void crew::crewdisplay()
{
	box crew;
	crew.smallbar(3,50,17);
	gotoxy(20,17);
	cout<<"Total pilots onboard       :  "<<pilots;
	crew.smallbar(3,50,19);
	gotoxy(20,19);
	cout<<"Total attendants onboard   :  "<<attends;

}