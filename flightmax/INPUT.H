#ifndef _input_h_
#define _input_h_

class input
{
	public:

		int validate(int x,int y,int max,int key,char* pstring,long double amount,char* msg2);
		char* validate(int x,int y,int max,int key,int key2,long double amount,char* msg);
		void wipevalues(int,int,int);

};

#endif
