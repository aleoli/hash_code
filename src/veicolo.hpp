#ifndef veicolo_hpp
#define veicolo_hpp

#include "dependencies.hpp"

using hs::Point;

namespace hs {

	class Veicolo {
	
	public:
		Veicolo();
		Veicolo(Ride ride);
		
		void set_ride(Ride ride);
		bool is_free();
		void next_step();
		Point get_position();
		
	private:
		vector<int> completed_rides;
		Point position;
		Ride current_ride;
		bool _is_free;
	
	};

}

#endif