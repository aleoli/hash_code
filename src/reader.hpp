#ifndef reader_hpp
#define reader_hpp

#include "dependencies.hpp"

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

using hs::Point;
using hs::MapConfig;
using hs::Ride;

namespace hs {
	
	class Reader {
	
	public:
		Reader(string);
    MapConfig GetMap();
    vector<Ride> GetRides();
		
  private:
    MapConfig mMap;
    vector<Ride> mRides;
    
	};
	
}

#endif