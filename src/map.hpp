#ifndef map_hpp
#define map_hpp

#include "dependencies.hpp"
#include "veicolo.hpp"

using hs::MapConfig;
using hs::Ride;
using hs::Point;
using hs::Veicolo;

namespace hs {

	class _Map {
	
	public:
		_Map(MapConfig conf, vector<Ride> rides);
		
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
	
	};

}

#endif