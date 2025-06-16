#include "aero.h"
#ifndef _crew_h_
#define _crew_h_

class crew : public aeroplane
{
	public:
		crew():pilots(0),attends(0) { }
		void crewinput();
		void crewdisplay();
	protected:
		int pilots,attends;



};

#endif