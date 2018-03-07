#include "reader.hpp"
using hs::Reader;

#include <fstream>

using std::ifstream;

Reader::Reader(string file_name) {
	
	ifstream f(file_name);
	
	f >> this->mMap.rows >> this->mMap.cols >> this->mMap.n_v >> this->mMap.rides >> this->mMap.bonus >> this->mMap.steps;
	int id = 0;
	while(true) {
		Ride r;
		r.id = id;
		if(!(f >> r.start.x >> r.start.y >> r.end.x >> r.end.y >> r.st_t >> r.end_t)) {
			break;
		}
		cout << r.start.x << " " << r.start.y << " " << r.end.x << " " << r.end.y << " " << r.st_t << " " << r.end_t << endl;
		this->mRides.push_back(r);
		id++;
	}
}

MapConfig Reader::GetMap() {
	return this->mMap;
}

vector<Ride> Reader::GetRides() {
	return this->mRides;
}
