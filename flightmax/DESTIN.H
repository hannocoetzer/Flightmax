#include "aero.h"
#ifndef _destin_h_
#define _destin_h_

class destination : public aeroplane
{
	public:
		destination():dist(0),cost(0),booked(0),needed(0) { }

		void destinput();
		void destdisplay();

	protected:
		float dist, cost;//, seatprice, profit, totprof;
		int   booked, needed;

};

#endif