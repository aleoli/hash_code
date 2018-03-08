#include "veicolo.hpp"
using hs::Veicolo;

#include "direction.hpp"
using hs::Direction;

#include "map.hpp"
using hs::_Map;

Veicolo::Veicolo(int id, _Map *map) {
	this->id = id;
	this->map = map;
	this->_is_free = true;
	this->effective_ride = false;
}

Veicolo::Veicolo(int id, Ride ride, _Map *map) {
	this->id = id;
	this->map = map;
	this->position = ride.start;
	this->current_ride = ride;
	this->_is_free = false;
	this->effective_ride = true;
}

int Veicolo::getId() {
	return this->id;
}

bool Veicolo::is_free() const {
	return this->_is_free;
}

void Veicolo::next_step() {
	if(!this->_is_free && this->current_ride.id >= 0) {
		if(this->effective_ride) {
			//cout << "Veicolo " << this->id << ": pos(x: " << this->position.x << ", y: " << this->position.y << ")" << "\tdestination: (x: " << this->current_ride.end.x << ", y: " << this->current_ride.end.y << ")" << endl;
			Direction *dir = new Direction(this->position, this->current_ride.end, this->map->get_points(this->position), this->map->get_l(), this->map->get_a());
			Direzione d = dir->GetDirection();
			this->move(d);
			delete dir;
		} else {
			//cout << "Veicolo " << this->id << ": pos(x: " << this->position.x << ", y: " << this->position.y << ")" << "\tdestination: (x: " << this->current_ride.start.x << ", y: " << this->current_ride.start.y << ")" << endl;
			//cout << "moving to next ride" << endl;
			Direction *dir = new Direction(this->position, this->current_ride.start, /*this->map->get_points(this->position)*/ Path(), this->map->get_l(), this->map->get_a());
			Direzione d = dir->GetDirection();
			this->move(d);
			delete dir;
		}
	}/* else {
		cout << (this->_is_free ? "free" : "not free") << "\tid: " << this->current_ride.id << "\tstart(x: " << this->current_ride.start.x << ", y: " << this->current_ride.start.y << ")" << "\tend(x: " << this->current_ride.end.x << ", y: " << this->current_ride.end.y << ")" << "\tmap(l: " << this->map->get_l() << ", a: " << this->map->get_a() << ")" << endl;
	}*/
}

vector<int> Veicolo::get_completed_rides() const {
	return this->completed_rides;
}

void Veicolo::move(Direzione d) {
	switch(d) {
	case UP:
		//cout << "moving up" << endl;
		this->position.y++;
		break;
	case DOWN:
		//cout << "moving down" << endl;
		this->position.y--;
		break;
	case LEFT:
		//cout << "moving left" << endl;
		this->position.x--;
		break;
	case RIGHT:
		//cout << "moving right" << endl;
		this->position.x++;
		break;
	default:
		break;
	}
	if(this->effective_ride) {
		if(this->position.x == this->current_ride.end.x && this->position.y == this->current_ride.end.y) {
			// ride finito
			this->ride_finished();
		}
	} else {
		if(this->position.x == this->current_ride.start.x && this->position.y == this->current_ride.start.y) {
			// inizia ride
			this->effective_ride = true;
		}
	}
}

void Veicolo::ride_finished() {
	this->completed_rides.push_back(this->current_ride.id);
	cout << "completed ride " << this->current_ride.id << endl;
	this->current_ride.id = -1;
	this->_is_free = true;
}

Point Veicolo::get_position() const {
	return this->position;
}

void Veicolo::set_ride(Ride ride) {
	cout << "setting ride " << ride.id << endl;
	this->current_ride = ride;
	this->effective_ride = (ride.start.x == this->position.x && ride.start.y == this->position.y);
	//cout << endl << "veicolo " << this->getId() << " starting ride to " << ride.start.x << " " << ride.start.y << endl << endl;
	this->_is_free = false;
}
