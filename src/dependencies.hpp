#ifndef dependencies_hpp
#define dependencies_hpp

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

namespace hs {
    
    typedef struct {
    	int rows;
    	int cols;
    	int n_v;
    	int rides;
    	int bonus;
    	int steps;
    } MapConfig;
    
    typedef struct {
    	int x;
    	int y;
    } Point;
    
    typedef struct {
    	int id;
    	Point start;
    	Point end;
    	int st_t;
    	int end_t;
    } Ride;
    
    typedef enum {
    	UP, DOWN, LEFT, RIGHT, NONE
    } Direzione;
    
    class Veicolo;
    class _Map;
    class Reader;
    class Direction;
    
}

#endif
