#ifndef dependencies_hpp
#define dependencies_hpp

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Reader{
    private:
    Dependencies._MapConfig mMap;
    vector<Dependencies.Ride> mRides;
    public:
    Reader(string);
    Dependencies._MapConfig GetMap();
    vector<Dependencies.Ride> GetRides();
};

#endif