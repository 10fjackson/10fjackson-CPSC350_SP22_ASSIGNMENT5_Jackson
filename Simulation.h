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

    void updateWaitTime(GenQueue<Student> *q);
    void updateIdleTime(Windows **w);


    void printStatistics();
    float meanStudentWaitTime();
    int medianStudentWaitTime();
    int maxStudentWaitTime();
    int studentOver10Min();
    float meanIdleTime();
    int maxIdleTime();
    int windowsOver5Min();




    GenQueue<Student> *queue;
    Windows **w;
    Windows *empty = new Windows();
    GenQueue<int> *waitTimes;
    GenQueue<int> *idleTimes;
    int worldClock = 0;
    int numOpenWindows = 0;
    int numStudentsArrived = 0;
    int timeNeeded = 0;
    int numberStudents = 0;
    int cap = 0;
    int time = 0;


private:
    float averageWaitTime;
    int studentMaxWait;
    int student10Min;

    float averageIdleTime;
    int maxIdle;
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

void Simulation::updateIdleTime(Windows **w){
    for(int i = 0; i < cap; i++){
        if(w[i]->isEmpty()){
            w[i]->updateIdleTime();
        }
    }
}

void Simulation::updateWaitTime(GenQueue<Student> *q){
    int i = 0;
    while(i <= q->getSize()){
        Student *s = q->remove();
        int data = s->updateWindowTime();
        q->insert(data);
        i++;
    }
}

void Simulation::printStatistics(){
    cout << "Average student wait time = " << meanStudentWaitTime() << endl;
    cout << "Median student wait time = " << medianStudentWaitTime() << endl;
    cout << "Max student wait time = " << maxStudentWaitTime() << endl;
    cout << "Number of students who waited over 10 minutes = " << studentOver10Min() << endl;

    cout << "Average window dile time = " << meanIdleTime() << endl;
    cout << "Max window dile time = " << maxIdleTime() << endl;
    cout << "Number of windows that were idle for over 5 minutes = " << windowsOver5Min() << endl;
}

float Simulation::meanStudentWaitTime(){
    int totalWaitTime = 0;
    int count = 0;
    while(count <= waitTimes->getSize()){
        int data = waitTimes -> remove();
        totalWaitTime += data;
        count++;
        waitTimes->insert(data);
    }

    averageWaitTime = totalWaitTime / count;
    return averageWaitTime;
}

void Simulation::medianStudentWaitTime(){

}

int Simulation::maxStudentWaitTime(){
    studentMaxWait = 0;
    int count = 0;
    while(i <= waitTimes->getSize()){
        int data = waitTimes -> remove();
        if(data > studentMaxWait){
            studentMaxWait = data;
        }
        count++;
        waitTimes->insert(data);
    }
    return studentMaxWait;
}

int Simulation::studentOver10Min(){
    student10Min = 0;
    int count = 0;
    while(count <= waitTimes->getSize()){
        int data = waitTimes -> remove();
        if(data > 10){
            student10Min++;
        }
        count++;
        waitTimes->insert(data);
    }
    return student10Min;
}

float Simulation::meanIdleTime(){
    int totalIdleTime = 0;
    int count = 0;
    while(count <= idleTimes->getSize()){
        int data = idleTimes -> remove();
        totalIdleTime += data;
        count++;
        idleTimes->insert(data);
    }

    averageIdleTime = totalIdleTime / count;
    return averageIdleTime;
}

int Simulation::maxIdleTime(){
    maxIdle = 0;
    int count = 0;
    while(i <= idleTimes->getSize()){
        int data = idleTimes -> remove();
        if(data > maxIdle){
            maxIdle = data;
        }
        count++;
        idleTimes->insert(data);
    }
    return maxIdle;
}

int Simulation::windowsOver5Min(){
    idle5Min = 0;
    int count = 0;
    while(count <= idleTimes->getSize()){
        int data = idleTimes -> remove();
        if(data > 5){
            idle5Min++;
        }
        count++;
        idleTimes->insert(data);
    }
    return idle5Min;
}
