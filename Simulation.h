#include <iostream>
#include <fstream>
#include "GenQueue.h"
#include "DoublyLinkedList.h"
#include "Student.h"
#include "Windows.h"
//Creates Simulation class
class Simulation
{
public:
    Simulation();
    Simulation(int t);
    ~Simulation();

    void processFile(string file);
    void createSimulation(string text);

    GenQueue *g = new GenQueue();
    Windows *w;

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
    createSimulation(text);
}

void Simulation::createSimulation(string text)
{
    int i = 0;
    w = new Windows(text[i++]);
    while(i < text.length()){
        w.setWindowTime(text[i++]);
        w.setNumberStudent(text[i++])
        for(int j = 0; j < w.getNumberStudent(); j++){
            Student *s = new Student(text[i++]);
            g.insert(s);
            cout << g.peak() << endl;

        }
    }
}
