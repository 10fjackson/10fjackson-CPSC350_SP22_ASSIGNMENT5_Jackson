#include "Simulation.h"
using namespace std;
int main(int argc, char **argv){
    Simulation s;
    s.processFile("test.txt");
    s.printStatistics();

}
