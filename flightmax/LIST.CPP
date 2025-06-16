#include "list.h"
#include <iostream.h>
#include <conio.h>

struct arrtype
{
	int arrdist;
	char arrnum[30];
	flight* arrnode;

};


void node::additem(char xflightnum[30],char xtype[30],int xnum
				,float xcsumpt,float xdist,float xcost,int xbooked
				  ,int xpilots,int xattends)

{
	flight* temp = new flight;
	if(head!=NULL)
	{
		temp->next=head;
		head=temp;
	}
	else
	{
		head = temp;
		head->next = NULL;

	}

	strcpy(head->flightnum,xflightnum);
	strcpy(head->type,xtype);
	head->num = xnum;
	head->csumpt = xcsumpt;
	head->dist = xdist;
	head->cost = xcost;
	head->booked = xbooked;
	head->pilots = xpilots;
	head->attends = xattends;

}

void node::display()
{
	flight* temp = head;
	while(temp!=NULL)
	{
		temp->fligdisplay();
		temp=temp->next;
	}

}

void node::delitem(int recnum)
{
	flight* temp = head;
	flight* prev = head;
	while(temp!=NULL)
	{
		if(temp->num==recnum)
		{

			temp->fligdisplay();
			prev->next=temp->next;

			delete temp;

		}
		prev=temp;
		temp=temp->next;
	}

}

void node::sortalpha()
{
	flight* temp = head;

	if(temp!=NULL)
	{
		arrtype index[25];
		arrtype temp2;
		int count = 0;
		flight* arrtemp;
		char tempnum[30];
		while(temp!=NULL)
		{
			strcpy(index[count].arrnum,temp->type);
			index[count].arrnode = temp;
			temp = temp->next;
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
		/*			arrtemp = index[g].arrnode;
					strcpy(tempnum,index[g].arrnum);
					index[g].arrnode = index[g+1].arrnode;
					strcpy(index[g].arrnum,index[g+1].arrnum);
					index[g+1].arrnode = arrtemp;
					strcpy(index[g+1].arrnum,tempnum);*/
		  //			flag=1;
					flag=1;
				}
			}


		}while(flag);
		for(int b = 0;b<count;b++)
		{
			index[b].arrnode->fligdisplay();
		}
	}
}

void node::sortnumeric()
{
	flight* temp = head;
	int count = 0;
	arrtype index[25];
	flight* arrtemp;
	int tempnum;

	if(temp!=NULL)
	{
		while(temp!=NULL)
		{
			index[count].arrdist = temp->dist;
			index[count].arrnode = temp;
			temp = temp->next;
			count++;
		}
		int flag;

		do
		{
			flag=0;
			for(int g=0;g<count;g++)
			{
				if(index[g].arrdist>index[g+1].arrdist)
				{
					arrtemp = index[g].arrnode;
					tempnum = index[g].arrdist;
					index[g].arrnode = index[g+1].arrnode;
					index[g].arrdist = index[g+1].arrdist;
					index[g+1].arrnode = arrtemp;
					index[g+1].arrdist = tempnum;
					flag=1;
				}
			}


		}while(flag);
	}
		ofstream outfile;
		outfile.open("PRN");
		for(int b = 0;b<count;b++)
		{
			outfile<<index[b].arrnode->flightnum<<endl;
			outfile<<index[b].arrnode->type<<endl;
			outfile<<index[b].arrnode->num<<endl;
			outfile<<index[b].arrnode->csumpt<<endl;
			outfile<<index[b].arrnode->dist<<endl;
			outfile<<index[b].arrnode->cost<<endl;
			outfile<<index[b].arrnode->booked<<endl;
			outfile<<index[b].arrnode->pilots<<endl;
			outfile<<index[b].arrnode->attends<<endl;
			getch();
		}
		getch();



}

void node::save(ofstream& savedata)
{

	window(1,1,80,25);
	clrscr();
	flight* temp = head;
	while(temp!=NULL)
	{
//		ofstream saveda("data.txt",ios::binary,ios::app);

/*		cout<<temp->type<<endl;
		cout<<temp->flightnum<<endl;
		cout<<temp->csumpt<<endl;
		cout<<temp->booked<<endl;
		cout<<temp->cost<<endl;
		cout<<temp->pilots<<endl;
		cout<<temp->attends<<endl;
		cout<<temp->num<<endl;
		cout<<endl;  */
//		getch();

		temp->fligdisplay();
		temp->savefile(savedata);

		temp=temp->next;
//		saveda.close();

	}
	cout<<"about to quit";
	getch();
}
