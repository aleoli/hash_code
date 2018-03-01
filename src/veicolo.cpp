#include "veicolo.hpp"
using ns::Veicolo;

Veicolo::Veicolo() {
	this->_is_free = true;
}

Veicolo::Veicolo(Ride ride) {
	this->position = ride.start;
	this->current_ride = ride;
	this->_is_free = false;
}

bool Veicolo::is_free() {
	return this->_is_free
}

void Veicolo::next_step() {
	
}

Point Veicolo::get_position() {
	return this->position;
}
