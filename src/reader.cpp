#include "reader.hpp"

using ns::Reader;

Reader::Reader(string file_name){
    int n_row,n_col,n_vei,n_rid,n_bon,n_step;
    int** vec;
    FILE* f=fopen(file_name,"r");
    
    fscanf(f,"%d %d %d %d %d %d",&n_row,&n_col,&n_vei,&n_rid,&n_bon,&n_step);
    
    vec=malloc(n_rid*sizeof(int*));
    for(int i=0;i<n_rid;i++){
        vec[i]=malloc(6*sizeof(int));
        fscanf(f,"%d %d %d %d %d %d",&vec[i][0],&vec[i][1],&vec[i][2],&vec[i][3],&vec[i][4],&vec[i][5]);
    }
    
    mMap.rows=n_row;
    mMap.cols=n_col;
    mMap.n_v=n_vei;
    mMap.rides=n_rid;
    mMap.bonus=n_bon;
    mMap.steps=n_step;
    
    for(int i=0;i<n_rid;i++){
        for(int j=0;j<6;j++){
            mRides.push_back(vec[i][j]);
        }
    }
    
}

Dependencies.MapConfig GetMap(){return mMap}

vector<Dependencies.Ride> GetRides(){return mRides}
