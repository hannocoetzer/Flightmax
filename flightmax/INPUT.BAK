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
#include <iostream.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "box.h"
#include <iomanip.h>
#include <dos.h>

/*----------------------------Value range check---------------------------*/

int input::validate(int x,int y,int max,int key2,char *pstring,long double amount,char* msg2)
{

	float temp;
	char* number2;
	long double number;
	int valid=0;
	number=atol(pstring);

	if(number>amount)
	{
		gotoxy(key2,1);
		_setcursortype(_NORMALCURSOR);
		box hl(25,8,55,13,RED,WHITE,0,1,1,"Error Display");
		hl.save();
		hl.show();
		gotoxy(4,3);
		cout<<msg2;
		gotoxy(9,5);
		cout<<"Press any key";
		getch();

		hl.load();
		textcolor(BLACK);
		textbackground(GREEN);
		hl.smallbar(max,x,y);
		valid=1;
		_setcursortype(_SOLIDCURSOR);

	}

	return valid;
}


/*-----------------------------Validating function-------------------------*/

char* input::validate(int x,int y,int max,int key,int key2,long double amount,char *msg2)
{
	int valid=0,alpval=0,count=0;
	char pstring[60];
	char msg[60];
	char alpha[]={"abcdefghijklmnopqrstuvwxyz"};
	char hialpha[]={"ABCDEFGHIJLNOPQRTUVWQYZ"};
	char dotnumb[]={"0123456789."};
	char nondotnumb[]={"0123456789"};
	char punct[]={'\x20','\r','\x08'};
	char ch,ch2;
	pstring[0]=max+1;


	do
	{
		for(int l=0;l<60;l++)      //clean string with null character
		{
			 pstring[l]='\x0';
		}
		count=0;
		valid=0;
		gotoxy(x,y);
		do
		{
			alpval=0;
			gotoxy(x+count,y);
			ch=getch();                    //input character

			if(ch=='K')
			{
				gotoxy(x+count,y);
				cout<<ch;
				pstring[count]=ch;
				alpval=1;
			}
			if(ch=='M')
			{
				gotoxy(x+count,y);
				cout<<ch;
				pstring[count]=ch;
				alpval=1;
			}
			if(ch=='S')
			{
				cout<<ch;
				pstring[count]=ch;
				alpval=1;
			}
			if(ch==0)                             //left and right keys
			{
				ch=getch();
				if(ch=='K'&&count>0)
				{

					gotoxy(x+count-1,y);            //left cursor
					count=count-2;
					alpval=1;
				}
				if(ch=='M')                        //right cursor
				{
					gotoxy(x+count,y);
					alpval=1;
				}
				if(ch=='S'&&count>0)               //delete key
				{
					count=count-1;
					gotoxy(x+count+1,y);
					cout<<"\xB1";
					pstring[count+1]=' ';
					alpval=1;
				}

			}
			if(key==0)
			{
				for(int b=0;b<12;b++)
				{
					if(ch==nondotnumb[b]||ch==punct[b])
					{
						gotoxy(x+count,y);          //check for specific
						cout<<ch;                   //  characters
						pstring[count]=ch;
						alpval=1;
					}
					else
						strcpy(msg,"No letters or dot allowed");

				}
			}

			if(key==1)
			{
				for(int b=0;b<27;b++)
				{
					if(ch==alpha[b]||ch==punct[b]||ch==hialpha[b])
					{
						gotoxy(x+count,y);
						cout<<ch;                   //special characters
						pstring[count]=ch;
						alpval=1;
					}
					else
						strcpy(msg,"  Only letters allowed");
				}
			}
			if(key==2)
			{
				for(int b=0;b<12;b++)
				{
					if(ch==dotnumb[b]||ch==punct[b])
					{
						gotoxy(x+count,y);
						cout<<ch;                    //special characters
						pstring[count]=ch;
						alpval=1;
					}
					else
						strcpy(msg,"  Only numbers allowed");
				}

			}
			if(alpval!=1)
			{
				_setcursortype(_NORMALCURSOR);
				box error(25,8,55,13,RED,WHITE,0,1,1,"Error Display");
				error.save();
				error.show();
				gotoxy(4,3);
				cout<<msg;
				gotoxy(9,5);
				cout<<"Press any key";
				getch();
				error.load();
				textcolor(BLACK);
				textbackground(GREEN);
				pstring[count]='\x20';
				gotoxy(x+count,y);              //if error flag
				cout<<"\xB1";
				count--;
				_setcursortype(_SOLIDCURSOR);

			}
			if(pstring[0]=='\r')
			{
				count=-1;
				pstring[0]='\x0';
			}
			if(ch=='\x20'&&count<=max)
			{
				gotoxy(x+count,y);              //space key
				cout<<"\xB1";
				pstring[count]=ch;

			}
			if(ch=='\x08'&&count>0)            //backspace key
			{
				gotoxy(x+count-1,y);
				cprintf("\xB1");
				count=count-2;
			}
			if(count>max)
			{
				gotoxy(x+count,y);
				cprintf("\xB1");
				count--;
			}
			count++;
			if(key==2||key==0)
			{

				valid=validate(x,y,max,key2,pstring,amount,msg2); //check the value range
				if(valid==1)
				{
					gotoxy(x+count,y);
					for(int s=0;s<max;s++)
					{
						pstring[s]='\x0';
					}

					count=0;
				}
			}
		}while(ch!='\r'||pstring[0]=='\x0');

	}while(valid==1);

	return pstring;
}

/*----------------Fucntion to clean values--------------------------*/

void input::wipevalues(int length,int x,int y)
{
	gotoxy(x,y);

	for(int s=0;s<length;s++)
	{
		cout<<" ";
	}


}
/*void program::intro()
{
	char buffer[80];
	int y = 0;
	box intro(20,7,60,22,WHITE,BLUE,1,1,1,"Intro Screen");
	intro.show();
	window(10,9,70,21);
	ifstream intr("intro.txt");
//	cout<<endl;
	while(!intr.eof())
	{
		y++;
		intr.getline(buffer,80);
		gotoxy(((70-10)/2)-(strlen(buffer)/2),y);
		cout<<buffer;
//		cout<<strlen(buffer);
//		getch();
  //		y++;
	}
	intr.close();
	getch();

}
//	intro();
*/
