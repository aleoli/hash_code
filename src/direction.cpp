#include "direction.hpp"
using hs::Direction;

#include "a_st.hpp"
using hs::A_st;

Direction::Direction(Point a,Point b,vector<Point> pos_occ,int l,int h) {
	this->start = a;
	this->end = b;
	this->occ = pos_occ;
	this->h = h;
	this->l = l;
	A_st *p = new A_st(a, b, pos_occ, l, h);
	Path path = p->get_path();
	if(path.empty()) {
		this->mDir = NONE;
	}
	this->mDir = NONE;
	Point f_m = path[0];
	cout << "first move: x: " << f_m.x << ", y: " << f_m.y << endl;
	if(f_m.x > a.x) {
		this->mDir = RIGHT;
	} else if(f_m.x < a.x) {
		this->mDir = LEFT;
	} else if(f_m.y > a.y) {
		this->mDir = UP;
	} else if(f_m.y < a.y) {
		this->mDir = DOWN;
	}
	delete p;
}

/*Direction::Direction(Point a,Point b,vector<Point> pos_occ,int l,int h){
    
    bool lib;
    
    if(b.x==a.x&&b.y==a.y){
        mDir=NONE;
    }else{
    
    if(b.x>a.x){
        lib=true;
        for(auto it=pos_occ.begin(); it!=pos_occ.end(); ++it) {
            if(a.x+1==it->x)
                lib=false;
        }
        if(lib==true){
            mDir=RIGHT;
        }
    }else if(b.x==a.x){
        lib=false;
    }else{
        lib=true;
        for(auto it=pos_occ.begin(); it!=pos_occ.end(); ++it) {
            if(a.x-1==it->x)
                lib=false;
        }
        if(lib==true){
            mDir=LEFT;
        }
    }
    
    if(b.y>a.y&&lib==false){
        lib=true;
        for(auto it=pos_occ.begin(); it!=pos_occ.end(); ++it) {
            if(a.y+1==it->y)
                lib=false;
        }
        if(lib==true){
            mDir=UP;
        }else{
            mDir=NONE;
        }
    }else if(b.y==a.y&&lib==false){
        mDir=NONE;
    }else if(b.y<a.y){
        lib=true;
        for(auto it=pos_occ.begin(); it!=pos_occ.end(); ++it) {
            if(a.y-1==it->y)
                lib=false;
        }
        if(lib==true){
            mDir=DOWN;
        }else{
            mDir=NONE;
        }
    }
    
    }
    
}*/

Direzione Direction::GetDirection(){
    return this->mDir;
}