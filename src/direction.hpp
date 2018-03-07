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
	
	class Direction {
	
	public:
    Direction(Point,Point,vector<Point>,int l,int h);
    Direzione GetDirection();
    
   private:
    Direzione mDir;
    Point start;
    Point end;
    vector<Point> occ;
    int h, l;
	};
	
}

#endif