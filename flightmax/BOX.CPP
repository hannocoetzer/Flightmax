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
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream.h>

struct text_info ti;

/*------------------------Drawing box fucntion----------------------*/

void box::show()
{
//	free();
	int j,width,height,ans;										// variables
	if(key==1)
	{
		window(1,1,80,25);
		textbackground(BLUE);
		clrscr();

	}

	if(key2==1)
	{
		window(left+2,top+1,right+2,bottom+1);
		textbackground(BLACK);
		clrscr();
	}

	window(left,top,right,bottom);
	textbackground(tbgcolour);
	textcolor(tecolour);
	clrscr();             									// clears the screen
	window(left,top,right,bottom+1);
	width=(right-left)+1;
	height=(bottom-top)+1;
	for(j=0;j<width;j++)    								// for loop
	{
		gotoxy(j,1);                                 //print character
		putch('\xcd');
	}
	gotoxy(1,1);
	putch('\xc9');                                  //print character
	gotoxy(width,1);
	putch('\xbb');
	for(j=2;j<height;j++) 									// for loop
	{
		gotoxy(1,j);
		putch('\xba');
		gotoxy(width,j);
		putch('\xba');                               //print character
	}
	for(j=1;j<width;j++) 									// for loop
	{
		gotoxy(j,height);
		putch('\xcd');
	}
	gotoxy(1,height);
	putch('\xc8');
	gotoxy(width,height);
	putch('\xbc');                                 //print character
	if(hdr==1)
	{
		ans=((right-left)/2)-(strlen(msg)/2);

		gotoxy(ans,1);
		cout<<msg;

	}
	window(left,top,right,bottom);
}

/*---------------------Delete box from memory fuction----------------*/

void box::show2(int key)
{
	window(1,1,80,25);
	clrscr();
	textbackground(BLUE);
	textcolor(DARKGRAY);
	showbar(1);
	showbar(9);
	showbar(15);
	if(key==1)
	{
		showbar(21);
		gotoxy(27,21);
		cout<<"CREW-TO-SEATS BOOKED RATIO";
	}
	gotoxy(33,1);
	cout<<"FLIGHT DETAILS";
	gotoxy(30,9);
	cout<<"DESTINATION DETAILS";
	gotoxy(34,15);
	cout<<"CREW DETAILS";

}

void box::save()
{
	window(1,1,80,25);
	gettextinfo(&ti);
	free();
	buffer=new char[5000];            //big buffer to save to screens
	gettext(1,1,80,25,buffer);
}

void box::hide()
{

	puttext(1,1,80,25,buffer);                         //free memory
	free();
	window(ti.winleft,ti.wintop,ti.winright,ti.winbottom);
	gotoxy(ti.curx,ti.cury);
//	delete[] buffer;                             //delete box buffer
}

void box::load()
{
	puttext(1,1,80,25,buffer);                         //free memory
	free();
	window(ti.winleft,ti.wintop,ti.winright,ti.winbottom);
	gotoxy(ti.curx,ti.cury);
	delete[] buffer;                             //delete box buffer


}

/*--------------------Drawing a small bar for input-------------------*/

void box::smallbar(int max,int x,int y)
{
	for(int b=0;b<max;b++)
	{                                          //for loop
		textbackground(GREEN);
		gotoxy(x+b,y);
		cprintf("\xB1");                         //character to display
	}

}

int box::menubox(int x,int y,int prev,int next,char names[6][39],int items)
{
	char ch;
	int ans,count=0,spacing[5];
	ans=(right-left)-1;
	for(int s=0;s<items;s++)
	{
		spacing[s]=((right-left)/2)-(strlen(names[s])/2);
		gotoxy(spacing[s],y+s);
		cprintf("%s",names[s]);
	}
	menubar(ans,x,y,next);
	textcolor(WHITE);
	gotoxy(spacing[0],y);
	cprintf("%s",names[0]);

	do
	{
		_setcursortype(_NOCURSOR);
		ch=getch();
		if(ch==0)
		{

			ch=getch();
			if(ch=='P')
			{
				count++;
				menubar(ans,x,y+count-1,prev);
				textcolor(BLUE);
				gotoxy(spacing[count-1],y+count-1);
				cprintf("%s",names[count-1]);
				if(count>items-1)
					count=0;
				menubar(ans,x,y+count,next);
				textcolor(WHITE);
				gotoxy(spacing[count],y+count);
				cprintf("%s",names[count]);

			}
			if(ch=='H')
			{
				count--;
				menubar(ans,x,y+count+1,prev);
				textcolor(BLUE);
				gotoxy(spacing[count+1],y+count+1);
				cprintf("%s",names[count+1]);
				if(count<0)
					count=items-1;
				menubar(ans,x,y+count,next);
				textcolor(WHITE);
				gotoxy(spacing[count],y+count);
				cprintf("%s",names[count]);
			}
		}
	}while(ch!='\r');
	return count;
}

void box::menubar(int max,int x,int y,int color)
{
	for(int b=0;b<max;b++)
	{                                          //for loop
		gotoxy(x+b,y);

		textbackground(color);
		cprintf(" ");
	}


}

void box::showbar(int y)
{
		for(int b=1;b<81;b++)
		{                                          //for loop
			gotoxy(b,y);

			textbackground(LIGHTGRAY);
			cprintf(" ");
		}

}