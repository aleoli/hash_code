#ifndef veicolo_hpp
#define veicolo_hpp

#include "dependencies.hpp"

using hs::Point;
using hs::_Map;

namespace hs {

	class Veicolo {
	
	public:
		Veicolo(int id, _Map *map);
		Veicolo(int id, Ride ride, _Map *map);
		
		void set_ride(Ride ride);
		bool is_free() const;
		void next_step();
		Point get_position() const;
		vector<int> get_completed_rides() const;
		int getId() const;
		
	private:
		void move(Direzione d);
		void ride_finished();
		
		int id;
		_Map *map;
		vector<int> completed_rides;
		Point position;
		Ride current_ride;
		bool _is_free;
	
	};

}

#endif