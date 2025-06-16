#include "node.h"
#ifndef _prog_h_
#define _prog_h_

class program
{
	public:
		program():head(0){}
		void process();
		void add(node* temp);
		void delnode();
		void write();
		void start();
		void numsort();
		void search();
		void printlist();
		void calculate();
		void intro();
		void outro();
	protected:
		node* head;

};

#endif