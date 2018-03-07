#ifndef a_st_hpp
#define a_st_hpp

#include "dependencies.hpp"

using hs::Point;
using hs::Path;

namespace hs {
	
	class A_st {
		
	public:
		A_st(Point start, Point end, vector<Point> occ, int h, int l);
		Path get_path();
		
	private:
		typedef struct {
			Point p;
			float weight;
			float dist;
		} Node;
		
		float get_dist(Point a, Point b);
		void add_nodes();
		void add_node(Node node);
		bool is_accessible(Point p);
		bool change_position();
		Node get_best();
		
		int h;
		int l;
		Node position;
		vector<Node> open;
		vector<Node> closed;
		vector<Point> occ;
		Point end;
		vector<Point> path;
		bool found;
		
	};
	
}

#endif