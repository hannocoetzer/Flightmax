#include "node.h"
#include "destin.h"
#include "crew.h"
#include <fstream.h>
#include <iostream.h>
#include <string.h>
#ifndef _flig_h_
#define _flig_h_

class flight : public destination , public crew
{
	public:
		flight():next(0),pointer(0),recnum(0)
		{
			strcpy(flightnum,"\0");	 //	flight tempi;

		}

		friend istream& operator >> (istream &s ,flight& d);
		friend ostream& operator << (ostream &s ,flight& d);
		void fliginput();
		int ratio();
		void fligdisplay();
		float getnum()
		{
			return dist;
		}
		char* getflightnum()
		{
			return flightnum;
		}
		float getcost()
		{
			return cost;
		}
		int getbooked()
		{
			return booked;
		}
		int getpilots()
		{
			return pilots;
		}
		int getattends()
		{
			return attends;
		}
		friend class node;
	protected:
		int recnum;
		node* pointer;
		char flightnum[30];
		flight* next;
};

#endif