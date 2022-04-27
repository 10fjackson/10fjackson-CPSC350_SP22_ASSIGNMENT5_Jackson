#include "Simulation.h"

int main(int argc, char **argv){
    Simulation s;
    s.processFile("test.txt");
    s.printStatistics();

}
