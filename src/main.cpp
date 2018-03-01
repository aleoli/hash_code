#include <iostream>

#include "hs.hpp"

using std::cout;
using std::endl;

using hs::Reader;
using hs::_Map;
using hs::Output;

int main(int argc, char *argv[]) {
    cout << "Hello World!" << endl;
    
    if(argc < 2) {
    	cout << "Mancano gli argomenti" << endl;
    }
    
    Reader *reader = new Reader(string(argv[1]));
    _Map *map = new _Map(reader->GetMap(), reader->GetRides());
    
    Output *output = new Output(map->get_cars());
    
    return 0;
}
