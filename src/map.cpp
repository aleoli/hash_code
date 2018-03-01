#include "map.hpp"
using hs::_Map;

_Map::_Map(MapConfig conf, vector<Ride> rides) {
	this->conf = conf;
	this->rides = rides;
	this->step = 0;
	for(int a=0; a<this->conf.n_v; a++) {
		Ride ride = this->get_ride(this->get_first());
		if(ride.id >= 0) {
			this->veicoli.push_back(new Veicolo(a, this));
		} else {
			this->veicoli.push_back(new Veicolo(a, ride, this));
		}
	}
	this->next_step();
}

vector<Point> _Map::get_points(Point exclude) {
	vector<Point> points;
	for(auto it=this->veicoli.begin(); it!=this->veicoli.end(); ++it) {
		Point pos = (*it)->get_position();
		if(pos.x == exclude.x && pos.y == exclude.y) {} else {
			points.push_back(pos);
		}
	}
	return points;
}

int _Map::get_l() const {
	return this->conf.cols;
}

int _Map::get_a() const {
	return this->conf.rows;
}

void _Map::next_step() {
	this->step++;
	if(step == this->conf.steps)
		return;
	for(auto it=this->veicoli.begin(); it!=this->veicoli.end(); ++it) {
		if((*it)->is_free()) {
			Ride ride = this->get_ride(this->get_best((*it)->get_position()));
			if(ride.id >= 0) {
				(*it)->set_ride(ride);
			}
		}
		(*it)->next_step();
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
	Ride best;
	best.id = -1;
	int min_start = 100000;
	for(auto it=this->rides.begin(); it!=this->rides.end(); ++it) {
		if(it->st_t < min_start) {
			min_start = it->st_t;
			best = (*it);
		}
	}
	return best.id;
}

Ride _Map::get_ride(int id) {
	for(auto it=this->rides.begin(); it!=this->rides.end(); ++it) {
		if(it->id == id) {
			Ride res = *it;
			this->rides.erase(it);
			return res;
		}
	}
}

int _Map::get_best(Point position) {
	vector<Ride> pending = this->get_pending_rides();
	Ride best;
	best.id = -1;
	int min_start = 100000;
	for(auto it=pending.begin(); it!=pending.end(); ++it) {
		if(it->start.x == position.x && it->start.y == position.y && it->st_t < min_start) {
			min_start = it->st_t;
			best = (*it);
		}
	}
	return best.id;
}



