#include "output.hpp"

using hs::Output;

Output::Output(vector<Veicolo*> vei){
    
    FILE* f;
    f=fopen("output.txt","w");
    
    for(auto it=vei.begin(); it!=vei.end(); ++it){
        fprintf(f,"%d ",(*it)->getId());
        for(auto it1=(*it)->get_completed_rides().begin(); it1!=(*it)->get_completed_rides().end(); ++it1){
            fprintf(f,"%d ",*it1);
        }
        fprintf(f,"\n");
    }
    fclose(f);
}