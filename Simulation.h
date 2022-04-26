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

    GenQueue<Student> *queue;
    Windows **w;
    Windows *empty = new Windows();
    GenQueue<int> *waitTimes;
    GenQueue<int> *IdleTimes;
    int worldClock = 0;
    int numOpenWindows = 0;
    int numStudentsArrived = 0;
    int timeNeeded = 0;
    int numberStudents = 0;
    int cap = 0;
    int time = 0;


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
    cap = text[i++];
    w = new Windows *[cap];
    for(int k = 0; k < cap; k++){
        w[i] = new Windows();
    }
    time = text[i++];
    while(i < text.length() || numOpenWindows != 0){
        worldClock++;

        if(worldClock == time){

            numberStudents = text[i++];

            for(int j = 0; j < numberStudents; j++){
                Student *s = new Student(text[i++]);
                queue.insert(s);
                cout << queue.peak() << endl;
            }

            int c = 0;

            while(c < cap && queue->!(isEmpty())){

                if(w[c]->isBusy()){
                    if(w[c]->timeNeeded() == 0){
                     w[c]->setEmpty();
                    }
                }

                if(w[c]->isEmpty()){
                    w[c]->setBusy(queue.remove());
                }

                c++;
            }
            time = text[i++];

        }
        else{
            //update student and window variables
        }
    }

}

void Simulation::updateWaitTime(GenQueue<Student> *q){
    int i = 0;
    while(i <= q->getSize()){
        Student *s = q->remove();
        s->updateWindowTime();
        q->insert(data);
        i++;
    }
}

void Simulation::updateIdleTime(){

}
