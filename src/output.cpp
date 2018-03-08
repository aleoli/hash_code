#include "output.hpp"

using hs::Output;

Output::Output(vector<Veicolo*> vei){
    
    FILE* f;
    f=fopen("output.txt","w");
    
    for(auto it=vei.begin(); it!=vei.end(); ++it) {
        fprintf(f,"%d ",(*it)->getId());
        vector<int> rides = (*it)->get_completed_rides();
        for(auto it1=rides.begin(); it1!=rides.end(); ++it1) {
            fprintf(f,"%d ",*it1);
        }
        fprintf(f,"\n");
    }
    fclose(f);
}