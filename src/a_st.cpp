#include "a_st.hpp"
using hs::A_st;

#include <cmath>

A_st::A_st(Point start, Point end, vector<Point> occ, int h, int l) {
	this->end = end;
	this->occ = occ;
	this->h = h;
	this->l = l;
	this->position.p = start;
	this->position.weight = 0;
	this->position.dist = this->get_dist(this->position.p, end);
	this->open.push_back(this->position);
	this->found = false;
	//cout << "Path from (x: " << start.x << ", y: " << start.y << ") to (x: " << end.x << ", y: " << end.y << ")" << endl;
	int a = 0;
	while(!(this->position.p.x == end.x && this->position.p.y == end.y)) {
		this->add_nodes();
		if(!this->change_position()) {
			// nessun percorso possibile
			break;
		}
		//cout << "x: " << this->position.p.x << ", y: " << this->position.p.y << endl;
		if(this->position.p.x != start.x || this->position.p.y != start.y) {
			this->path.push_back(this->position.p);
		}
		a++;
		if(a>10)
			break;
	}
	if(a <= 10) {
		this->found = true;
	}
}

float A_st::get_dist(Point a, Point b) {
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void A_st::add_nodes() {
	if(this->position.p.x + 1 < l) {
		// aggiungi nodo a destra
		Node n = this->position;
		n.p.x += 1;
		this->add_node(n);
	}
	if(this->position.p.y + 1 < h) {
		// aggiungi nodo in alto
		Node n = this->position;
		n.p.y += 1;
		this->add_node(n);
	}
	if(this->position.p.x - 1 >= 0) {
		// aggiungi nodo a sinistra
		Node n = this->position;
		n.p.x -= 1;
		this->add_node(n);
	}
	if(this->position.p.y - 1 >= 0) {
		// aggiungi nodo sotto
		Node n = this->position;
		n.p.y -= 1;
		this->add_node(n);
	}
	this->closed.push_back(this->position);
}

void A_st::add_node(Node node) {
	if(this->is_accessible(node.p)) {
		node.weight += 1;
		node.dist = this->get_dist(node.p, this->end);
		for(auto it=this->closed.begin(); it!=this->closed.end(); ++it) {
			if(node.p.x == it->p.x && node.p.y == it->p.y && (node.weight + node.dist*10) < (it->weight + it->dist*10)) {
				this->open.push_back(*it);
				this->closed.erase(it);
				return;
			}
		}
		this->open.push_back(node);
	}
}

bool A_st::is_accessible(Point p) {
	for(auto it=this->occ.begin(); it!=this->occ.end(); ++it) {
		if(p.x == it->x && p.y == it->y) {
			return false;
		}
	}
	return true;
}

bool A_st::change_position() {
	Node n = this->get_best();
	if(n.dist < 0) {
		return false;
	}
	this->position = n;
	return true;
}

A_st::Node A_st::get_best() {
	float min = -1;
	Node best;
	best.dist = -1;
	for(auto it=this->open.begin(); it!=this->open.end(); ++it) {
		if(it->weight + it->dist < min || min < 0) {
			min = it->weight + it->dist;
			best = *it;
		}
	}
	for(auto it=this->open.begin(); it!=this->open.end(); ++it) {
		if(it->p.x == best.p.x && it->p.y == best.p.y) {
			this->open.erase(it);
			break;
		}
	}
	return best;
}

Path A_st::get_path() {
	//if(this->found) {
		return this->path;
	/*} else {
		Path p;
		return p;
	}*/
}






