#include "map.hpp"
using hs::_Map;

_Map::_Map(MapConfig conf, vector<Ride> rides) {
	this->conf = conf;
	this->rides = rides;
	this->step = 0;
	for(int a=0; a<this->conf.n_v; a++) {
		Ride ride = this->get_ride(this->get_first());
		//if(ride == NULL) {
		//	this->veicoli.push_back(new Veicolo());
		//} else {
			this->veicoli.push_back(new Veicolo(ride));
		//}
	}
}

void _Map::next_step() {
	this->step++;
	if(step == this->conf.steps)
		return;
	for(auto it=this->veicoli.begin(); it!=this->veicoli.end(); ++it) {
		if((*it)->is_free()) {
			Ride ride = this->get_ride(this->get_best((*it)->get_position()));
			//if(ride != NULL) {
		//		(*it)->set_ride(ride);
			//}
		} else {
			(*it)->next_step();
		}
	}
	this->next_step();
}

vector<Ride> _Map::get_pending_rides() {
	vector<Ride> res;
	for(auto it=this->rides.begin(); it!=this->rides.end(); ++it) {
		if(it->st_t <= step) {
			res.push_back(*it);
		}
	}
	return res;
}

int _Map::get_first() {
	Ride *best = NULL;
	int min_start = 100000;
	for(auto it=this->rides.begin(); it!=this->rides.end(); ++it) {
		if(it->st_t < min_start) {
			min_start = it->st_t;
			best = &(*it);
		}
	}
	return best->id;
}

Ride _Map::get_ride(int id) {
	for(auto it=this->rides.begin(); it!=this->rides.end(); ++it) {
		if(it->id == id) {
			Ride res = *it;
			this->rides.erase(it);
			return res;
		}
	}
	throw std::exception();
}

int _Map::get_best(Point position) {
	vector<Ride> pending = this->get_pending_rides();
	Ride *best = NULL;
	int min_start = 100000;
	for(auto it=pending.begin(); it!=pending.end(); ++it) {
		if(it->start.x == position.x && it->start.y == position.y && it->st_t < min_start) {
			min_start = it->st_t;
			best = &(*it);
		}
	}
	return best->id;
}



