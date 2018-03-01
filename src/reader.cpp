#include "reader.hpp"

using hs::Reader;

Reader::Reader(string file_name){
    int n_row,n_col,n_vei,n_rid,n_bon,n_step;
    int** vec;
    FILE* f=fopen(file_name.c_str(),"r");
    
    fscanf(f,"%d %d %d %d %d %d",&n_row,&n_col,&n_vei,&n_rid,&n_bon,&n_step);
    
    vec=(int**)malloc(n_rid*sizeof(int*));
    for(int i=0;i<n_rid;i++){
        vec[i]=(int*)malloc(6*sizeof(int));
        fscanf(f,"%d %d %d %d %d %d",&vec[i][0],&vec[i][1],&vec[i][2],&vec[i][3],&vec[i][4],&vec[i][5]);
    }
    
    mMap.rows=n_row;
    mMap.cols=n_col;
    mMap.n_v=n_vei;
    mMap.rides=n_rid;
    mMap.bonus=n_bon;
    mMap.steps=n_step;
    
    for(int i=0;i<n_rid;i++){

        Ride tmp;//=(Ride*)malloc(sizeof(Ride));
        tmp.id=i;
        Point tmp_start;//=(Point*)malloc(sizeof(Point));
        Point tmp_end;//=(Point*)malloc(sizeof(Point));
        tmp_start.x=vec[i][0];
        tmp_start.y=vec[i][1];
        tmp.start=tmp_start;
        tmp_end.x=vec[i][2];
        tmp_end.y=vec[i][3];
        tmp.end=tmp_end;
        tmp.st_t=vec[i][4];
        tmp.end_t=vec[i][5];
        mRides.push_back(tmp);    
    }
    
}

MapConfig Reader::GetMap(){return this->mMap;}

vector<Ride> Reader::GetRides(){return this->mRides;}
