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
#include "node.h"
#include "flig.h"
#include <iostream.h>
#include <math.h>
#include <conio.h>

/*--------------------------Overloaded input----------------------------*/

istream& operator >> (istream &s ,flight& g)
{
	g.fliginput();
	return s;
}

/*--------------------------Overlaoded output----------------------------*/

ostream& operator << (ostream &s ,flight& g)
{

	g.fligdisplay();
	return s;
}

/*--------------------------Flight Input--------------------------------*/

void flight::fliginput()
{
	_setcursortype(_SOLIDCURSOR);
	box flig;
	flig.show2(0);
	gotoxy(20,3);
	cout<<"Aeroplane flight number : ";
	flig.smallbar(6,48,3);
	gotoxy(48,3);
	cin>>flightnum;
	destinput();
	crewinput();

}

/*-----------------------------Flight Display---------------------------*/

void flight::fligdisplay()
{
	textbackground(BLUE);
	textcolor(WHITE);
	clrscr();
	box flig;
	flig.show2(1);
	flig.smallbar(6,48,3);
	gotoxy(20,3);
	cout<<"Aeroplane flight number :   "<<flightnum;
	destdisplay();
	crewdisplay();
	flig.smallbar(6,50,23);
	gotoxy(20,23);
	cout<<"Crew-to-seats booked ratio :  "<<ratio();
}

/*-------------------------------Crew-to-seats-ratio---------------------*/

int flight::ratio()
{

	return (ceil(booked/(pilots+attends)));
}