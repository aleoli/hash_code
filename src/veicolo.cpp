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
}

Veicolo::Veicolo(int id, Ride ride, _Map *map) {
	this->id = id;
	this->map = map;
	this->position = ride.start;
	this->current_ride = ride;
	this->_is_free = false;
}

int Veicolo::getId() const {
	return this->id;
}

bool Veicolo::is_free() const {
	return this->_is_free;
}

void Veicolo::next_step() {
	if(!this->_is_free && this->current_ride.id >= 0) {
		Direction *dir = new Direction(this->position, this->current_ride.end, this->map->get_points(this->position), this->map->get_l(), this->map->get_a());
		Direzione d = dir->GetDirection();
		this->move(d);
	}
}

vector<int> Veicolo::get_completed_rides() const {
	return this->completed_rides;
}

void Veicolo::move(Direzione d) {
	switch(d) {
	case UP:
		this->position.y++;
		break;
	case DOWN:
		this->position.y--;
		break;
	case LEFT:
		this->position.x--;
		break;
	case RIGHT:
		this->position.x++;
		break;
	default:
		break;
	}
	if(this->position.x == this->current_ride.end.x && this->position.y == this->current_ride.end.y) {
		// ride finito
		this->ride_finished();
	}
}

void Veicolo::ride_finished() {
	this->completed_rides.push_back(this->current_ride.id);
	this->current_ride.id = -1;
	this->_is_free = true;
}

Point Veicolo::get_position() const {
	return this->position;
}

void Veicolo::set_ride(Ride ride) {
	this->current_ride = ride;
	this->_is_free = false;
}
