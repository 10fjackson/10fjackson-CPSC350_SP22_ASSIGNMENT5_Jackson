#include <iostream>
#include <fstream>
#include "GenQueue.h"
#include "DoublyLinkedList.h"
//Creates Simulation class
class Simulation
{
public:
    Simulation();
    Simulation(int t);
    ~Simulation();

private:

};
//Default Constructor
Simulation::Simulation()
{
}
//Default Destructor
Simulation::~Simulation()
{
}

void Simulation::processFile(string file) //takes in a file from the command line and sends data to genqueue
{
    string text = "";
    // takes command line argument
    ifstream infile(file); //open the file

    if (infile.is_open() && infile.good()) { // checks if file is good
        //cout << "File is now open!\nContains:\n";
        cout << "File is now open!"<<endl;
        string line = "";
        while (getline(infile, line)){
            text += line;
            text += '\n';
        }
        cout<< text <<endl;
    } else {
        cout << "Failed to open file"<<endl;
    }
}

void Simulation::createSimulation(string text)
{
    int i = 0;
    int windowsOpen = text[i++];
    int time = text[i++];
    int numberStudent = text[i++];
    for(int j = 0; j < numberStudent; j++){
        string waitTime += text[i++];
    }
    while(i < text.length()){
        time = text[i++];
        numberStudent = text[i++];
        for(int j = 0; j < numberStudent; j++){
            string waitTime += text[i++];
        }
    }
}
