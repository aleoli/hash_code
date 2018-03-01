#ifndef direction_hpp
#define direction_hpp

#include "dependencies.hpp"

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

using hs::Point;
using hs::Direzione;

namespace hs {
	
	class Direction{
    private:
    Direzione mDir;
    public:
    Direction(Point,Point,vector<Point>,int l,int h);
    Direzione GetDirection();
	};
	
}

#endif