#include "input.h"
#include <string.h>
#ifndef _aero_h_
#define _aero_h_

class aeroplane : public input
{
	public:
		aeroplane():num(0),csumpt(0.0)
		{

			strcpy(type,"\0");
		}

		void aeroinput();
		void aerodisplay();

	protected:
		char type[30];
		int num;
		float csumpt;
};

#endif