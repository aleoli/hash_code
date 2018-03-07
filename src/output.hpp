#ifndef output_hpp
#define output_hpp

#include "dependencies.hpp"
#include "veicolo.hpp"

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

using hs::Point;
using hs::Direzione;

namespace hs {
	
	class Output{
    public:
    Output(vector<Veicolo*>);
    };
	
}

#endif