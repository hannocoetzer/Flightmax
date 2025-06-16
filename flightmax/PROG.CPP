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
#include "prog.h"
#include <iomanip.h>
#include <process.h>
#include <stdio.h>
#include <iostream.h>
#include <dos.h>
#include <conio.h>
#include "flig.h"

struct arrtype                     //structure for swapping node pointers
{                                  //when sorting the records
	int arrdist;
	char arrnum[30];
	node* arrnode;

};

/*----------------Main fucntion of program---------------------------*/

void program::process()
{
	char ch;
	head = new node;
	char mainarr[6][39]={"Maintenace","Display","Print","Exit"};
	int mainch,mench,dispch,princh;
	start();
	intro();
	do
	{

		box men(23,10,57,16,WHITE,BLUE,1,1,1,"Main Menu");
		men.show();
		mainch=men.menubox(2,3,WHITE,BLUE,mainarr,4);

		if(mainch==0)
		{
			do
			{
				char mtenarr[6][39]={"Add new record","Delete a record","Do calculation","Return"};
				box mtenance(23,10,57,16,WHITE,BLUE,1,1,1,"Maintenance Menu");

				mtenance.show();
				mench=mtenance.menubox(2,3,WHITE,BLUE,mtenarr,4);
				if(mench==0)
				{
					flight* dat = new flight;
					cin>>*dat;
					node* newnode = new node(dat);
					add(newnode);
				}
				if(mench==1)
				{
					delnode();
				}
				if(mench==2)
				{
					calculate();
					window(1,1,80,25);
					clrscr();

				}
			}while(mench!=3);

		}
		if(mainch==1)
		{
			do
			{
				char disparr[6][39]={"Display full list in numeric order","Search records by flight number","Return"};
				box disp(15,10,65,16,WHITE,BLUE,1,1,1,"Display Menu");

				disp.show();
				dispch=disp.menubox(2,3,WHITE,BLUE,disparr,3);
				if(dispch==0)
				{
					numsort();
				}

				if(dispch==1)
				{
					search();

				}
			}while(dispch!=2);
			window(1,1,80,25);
			clrscr();
		}
		if(mainch==2)
		{
			do
			{
				char printarr[6][39]={"Print list in numeric form","Return"};
				box print(23,10,57,16,WHITE,BLUE,1,1,1,"Print Menu");

				print.show();
				princh=print.menubox(2,3,WHITE,BLUE,printarr,2);
				if(princh==0)
				{
					printlist();
				}
				if(princh==1)
				{
					gotoxy(1,1);
					cout<<"del";
				}
			}while(princh!=1);
			clrscr();
		}
	}while(mainch!=3);
	write();
	outro();
}

/*------------------------------Adding new nodes----------------------*/

void program::add(node* temp)
{
	temp->setnext(head);
	head = temp;

}

/*---------------------Sorting the records in numeric order---------*/

void program::numsort()
{
	node* curr =head;
	if(curr->getnext()!=0)
	{
		arrtype index[25];
		arrtype temp2;
		int count = 0;
		char tempnum[30];
		while(curr->getnext()!=0)
		{
			index[count].arrdist = curr->getdata()->getnum();
			index[count].arrnode = curr;
			curr = curr->getnext();
			count++;
		}
		int flag;

		do
		{
			flag=0;
			for(int g=0;g<count-1;g++)
			{
				if(index[g].arrdist>index[g+1].arrdist)
				{
					temp2 = index[g];
					index[g] = index[g+1];
					index[g+1] = temp2;
					flag=1;
				}
			}


		}while(flag);
		for(int b = 0;b<count;b++)
		{
			index[b].arrnode->getdata()->fligdisplay();
			gotoxy(22,25);
			cout<<"***Press any key to continue***";
			getch();

		}
	}
}

/*-----------------------Printout of all records---------------------*/

void program::printlist()
{
	node* curr =head;
		if(curr->getnext()!=0)
		{
			arrtype index[25];
			arrtype temp2;
			int count = 0;
			char tempnum[30];
			while(curr->getnext()!=0)
			{
				strcpy(index[count].arrnum,curr->getdata()->getflightnum());
				index[count].arrnode = curr;
				curr = curr->getnext();
				count++;
			}
			int flag;

			do
			{
				flag=0;
				for(int g=0;g<count-1;g++)
				{
					if(strcmpi(index[g].arrnum,index[g+1].arrnum)>0)
					{
						temp2 = index[g];
						index[g] = index[g+1];
						index[g+1] = temp2;
						flag=1;
					}
				}


			}while(flag);
			ofstream printout;
			clrscr();
			printout.open("CON");
			printout<<"\nFlight Number     Distance      Seat Price    Booked    Pilots    Attendants";
			printout<<"\n-------------   -----------     ----------    ------    ------    ----------\n";
			for(int b = 0;b<count-1;b++)
			{
				printout<<endl;

				printout<<b+1<<": ";//<<"            |          |            |        |        |           ";
				printout<<setw(7);
				printout<<index[b].arrnode->getdata()->getflightnum();
				printout<<"    | Km ";
				printout<<setw(9)<<index[b].arrnode->getdata()->getnum();//<<

				printout<<"  | R ";
				printout<<setw(8)<<index[b].arrnode->getdata()->getcost();//<<
				printout<<"  | ";
				printout<<setw(6)<<index[b].arrnode->getdata()->getbooked();//<<
				printout<<"  | ";
				printout<<setw(6)<<index[b].arrnode->getdata()->getpilots();//<<
				printout<<"  | ";
				printout<<setw(9)<<index[b].arrnode->getdata()->getattends();//<<
			}
		}
}

/*--------------------Function for deleting the records---------------*/

void program::delnode()
{
	char temp[30];
	char ch;
	int flag = 0;
	flight* des;

	window(1,1,80,25);
	clrscr();
	box del(15,10,65,14,WHITE,BLUE,1,1,1,"Delete record");
	del.show();
	gotoxy(5,3);
	cout<<"Enter flight number to delete  : ";
	del.smallbar(6,38,3);
	gotoxy(38,3);
	cin>>temp;
	node* curr = head;
	node* prevnode = head;
		while(curr)
		{

			if(strcmpi(temp,curr->getdata()->getflightnum())==0)
			{
				curr->getdata()->fligdisplay();
				gotoxy(17,25);
				cout<<"***Press [Y] if you want to delete this record***";
				ch=getch();
				flag = 1;
				if(ch=='y')
				{
					if(curr!=head)
						prevnode->setnext(curr->getnext());

					delete curr;
				}
			}
			prevnode = curr;
			curr = curr->getnext();
		}
		if(flag==0)
		{
			window(1,1,80,25);
			clrscr();
			box del(24,10,56,14,RED,WHITE,1,1,1,"Sorry");
			del.show();
			gotoxy(6,3);
			cout<<"No records was match";
			getch();
		}

}

/*---------------------------Writing records to disk------------------*/

void program::write()
{
	ofstream save("data.txt",ios::binary);
	node* curr = head;

	while(curr)
	{
		if(curr->getnext()!=0)
		{
			save.write((char*)curr->getdata(), sizeof(*curr->getdata()));
			curr = curr->getnext();
		}
		else if(curr->getnext()==0)
			curr = 0;
	}
	save.close();

}

/*-------------------------Reading records form file-------------------*/

void program::start()
{
	fstream file;


	file.open("data.txt", ios :: in | ios :: out | ios :: binary);
	if(!file)
	{
		cerr << "err";
		exit(1);
	}
	file.seekg(0, ios :: end);

	int size = file.tellg() / sizeof(flight);
	file.seekg(0, ios :: beg);
	for(int x = 0; x < size; x++)
	{
		flight* dat = new flight();

		file.read((char*)dat, sizeof(*dat));
		node* newnode = new node(dat);
		add(newnode);
	}

	file.close();


}

/*----------------------------Search for a specific record------------*/

void program::search()
{
	int flag = 0;

	node* curr = head;
		char temp[30];
		window(1,1,80,25);
		clrscr();
		box del(15,10,65,14,WHITE,BLUE,1,1,1,"Delete record");
		del.show();
		gotoxy(5,3);
		cout<<"Enter flight number to search  : ";
		del.smallbar(6,38,3);
		gotoxy(38,3);
		cin>>temp;

		while(curr)
		{

			if(strcmpi(temp,curr->getdata()->getflightnum())==0)
			{
				curr->getdata()->fligdisplay();
				gotoxy(22,25);
				cout<<"***Press any key to continue***";
				getch();
				flag = 1;
			}
			curr = curr->getnext();
		}
		if(flag==0)
		{
			window(1,1,80,25);
			clrscr();
			box del(24,10,56,14,RED,WHITE,1,1,1,"Sorry");
			del.show();
			gotoxy(6,3);
			cout<<"No records was match";
			getch();
		}

}

/*---------------------Calculate the higest and lowest ratio-----------*/

void program::calculate()
{
	node* curr = head;
	int lowtemp=999;
	int hightemp=0;
	int s;
	while(curr)
	{
		if(curr->getdata()->ratio()>hightemp)
		{
			hightemp=curr->getdata()->ratio();
		}
		if(curr->getdata()->ratio()<lowtemp)
		{
			lowtemp=curr->getdata()->ratio();
		}
		curr = curr->getnext();
	}
	box calc(15,10,69,16,WHITE,BLUE,1,1,1,"Crew-to-seats booked ratio");
	calc.show();
	gotoxy(4,3);
	cout<<"Lowest crew-to-seats ratio   : "<<lowtemp;
	gotoxy(4,5);
	cout<<"Higest crew-to-seats ratio   : "<<hightemp;
	getch();


}

/*---------------------------Intro function--------------------------*/

void program::intro()
{
	char buffer[80];
	int y = 0;
	ifstream intr("intro.txt");
	box intbox(10,8,70,22,WHITE,BLUE,1,1,1,"Intro Screen");
	intbox.show();
	window(11,9,69,21);
	while(!intr.eof())
	{
		y++;
		intr.getline(buffer,80);
		gotoxy(((69-11)/2)-(strlen(buffer)/2),y);
		cout<<buffer;
	}
	intr.close();
	window(1,1,80,25);
	int hour,min,sec,year,month,day;
	do
	{
		REGS timein,timeout;
		REGS datein,dateout;


		timein.h.ah = 0x2c;
		datein.h.ah = 0x2a;

		int86(0x21,&timein,&timeout);
		int86(0x21,&datein,&dateout);
		hour = timeout.h.ch;
		min = timeout.h.cl;
		sec = timeout.h.dh;
		year = dateout.x.cx;
		month = dateout.h.dh;
		day = dateout.h.dl;

		_setcursortype(_NOCURSOR);
		gotoxy(1,1);
		if(sec>59)
		{
			gotoxy(1,1);
			printf("                                   ");
		}
		if(min>59)
		{
			gotoxy(1,1);
			printf("                                   ");
		}
		if(hour>23)
		{
			gotoxy(1,1);
			printf("                                   ");
		}
		gotoxy(1,1);
		printf("Time -> %.2d : %.2d : %.2d ",hour,min,sec);
		gotoxy(30,1);
		printf("Date -> %d / %.2d / %.2d",year,month,day);
		gotoxy(58,1);
		printf("Mode -> 80x25 Colour");
	}while(!kbhit());
}

/*----------------------Outro screen-------------------------------*/

void program::outro()
{
	clrscr();
	box outro(20,12,60,18,WHITE,BLUE,1,1,1,"Outro Screen");
	outro.show();
	gotoxy(5,3);
	cout<<"Thankyou for using this product.";
	gotoxy(9,5);
	cout<<"Press any key to quit.";
	getch();
	textmode(C80);
	window(1,1,80,25);
	textbackground(BLACK);                    //set to default size and mode
	clrscr();
	_setcursortype(_NORMALCURSOR);

}
