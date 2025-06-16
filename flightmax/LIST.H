#ifndef _list_h_
#define _list_h_
#include "flig.h"

class list
{
	public:
		list()
		{
			head = NULL;
			head->next = NULL;
		}

		void additem(char flightnum[30],char type[30],int num
				,float csumpt,float dist,float xcost,int booked,int pilots
					,int attends);
		void save(ofstream& savedata);
		void display();
		void delitem(int recnum);
		void sortalpha();
		void sortnumeric();

	private:
		flight* head;

};

#endif