#ifndef map_hpp
#define map_hpp

#include "dependencise.hpp"
#include "veicolo.hpp"

namespace {

	class Map {
	
	public:
		Map(MapConfig conf, vector<Ride> rides);
		
	private:
		void next_step();
		int get_first();
		int get_best(Point position);
		vector<Ride> get_pending_rides();
		Ride get_ride(int id);
		
		MapConfig conf;
		vector<Ride> rides;
		vector<Veicolo *> veicoli;
		int step;
	
	}

}

#endif