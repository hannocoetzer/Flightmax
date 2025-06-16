#ifndef _node_h_
#define _node_h_
#include "flig.h"

class node
{
	public:
		node()
		{
			mydata = 0;
			next = 0;
		}
		node(flight* dat)
		{
			next = 0;
			mydata = dat;
		}
		flight* getdata()
		{
			return mydata;
		}
		node* getnext()
		{
			return next;
		}
			void setnext(node* temp)
		{

			if(temp==0)
			{
				next=0;
			}
			else
			{
				next = temp;
			}
		}
	private:
		flight* mydata;
		node* next;


};

#endif