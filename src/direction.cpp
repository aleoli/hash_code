#include "direction.hpp"

using hs::Direction;

Direction::Direction(Point a,Point b,vector<Point> pos_occ,int l,int h){
    
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
    
}

Direzione Direction::GetDirection(){
    return this->mDir;
}