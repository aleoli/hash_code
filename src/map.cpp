#include "map.hpp"
using hs::_Map;

#include "a_st.hpp"
using hs::A_st;

_Map::_Map(MapConfig conf, vector<Ride> rides) {
	this->conf = conf;
	this->rides = rides;
	this->step = 0;
	for(int a=0; a<this->conf.n_v; a++) {
		Ride ride = this->get_ride(this->get_first());
		if(ride.id >= 0) {
			//cout << a << " -> id: " << ride.id << ", x: " << ride.end.x << ", y: " << ride.end.y << endl;
			this->veicoli.push_back(new Veicolo(a, ride, this));
		} else {
			//cout << a << " -> creating with no ride" << endl;
			this->veicoli.push_back(new Veicolo(a, this));
		}
	}
	this->next_step();
}

vector<Veicolo *> _Map::get_cars() const {
	return this->veicoli;
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
	cout << endl << endl << "Step " << this->step << endl;
	if(step == this->conf.steps)
		return;
	for(auto it=this->veicoli.begin(); it!=this->veicoli.end(); ++it) {
		cout << endl << "veicolo " << (*it)->getId() << ": (x: " << (*it)->get_position().x << ", y: " << (*it)->get_position().y << ")" << endl;
		if((*it)->is_free()) {
			int best_id = this->get_best((*it)->get_position());
			//cout << best_id << endl;
			Ride ride = this->get_ride(best_id);
			if(ride.id >= 0) {
				//cout << (*it)->getId() << " -> id: " << ride.id << ", x: " << ride.end.x << ", y: " << ride.end.y << endl;
				//cout << "setting to veicolo " << (*it)->getId() << endl;
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
	Ride r;
	r.id = -1;
	return r;
}

int _Map::get_best(Point position) {
	vector<Ride> pending = this->rides; //this->get_pending_rides();
	Ride best;
	best.id = -1;
	unsigned int best_val = 100000;
	for(auto it=pending.begin(); it!=pending.end(); ++it) {
		//cout << "ride starts on " << it->start.x << " " << it->start.y << "\tends on " << it->end.x << " " << it->end.y << endl;
		A_st *perc = new A_st(position, it->start, Path(), this->get_a(), this->get_l());
		Path path = perc->get_path();
		if((it->st_t+path.size()) < best_val) {
			best_val = it->st_t+path.size();
			best.id = it->id;
		}
		delete perc;
	}
	return best.id;
}



