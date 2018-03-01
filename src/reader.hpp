#ifndef dependencies_hpp
#define dependencies_hpp

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Reader{
    Dependencies.MapConfig mMap;
    vector<Dependencies.Ride> mRides;
    public:
    Reader(string);
    Dependencies.MapConfig GetMap()
    vector<Dependencies.Ride> GetRides()
};

#endif