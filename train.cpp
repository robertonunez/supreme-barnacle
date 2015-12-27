/**
 * Training set generator for a simple neural net
 *
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <time.h>

#include <string>
#include <sstream>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

using namespace std;

int main() {
    srand(time(NULL));

    string filename = "./trainingData.txt";
    string label_top = "topology: 2 5 5 1\n"; // 2 inputs, two layers of 5, one output (plus hidden bias on every layer)
    string label_in = "in: ";
    string label_out = "out: ";
    ofstream trainingDataFile;

    trainingDataFile.open(filename.c_str());
    
    trainingDataFile << label_top;
    
    for (int i=0; i < 10000; i++) {
        double j = (double(rand()) / double(RAND_MAX)) / 2;
        double k = (double(rand()) / double(RAND_MAX)) / 2;
        double v = j + k;   
        trainingDataFile << label_in;
        trainingDataFile << patch::to_string(j) << " ";
        trainingDataFile << patch::to_string(k);
        trainingDataFile << endl;
        trainingDataFile << label_out;        
        trainingDataFile << patch::to_string(v);
        trainingDataFile << endl;
    }
}