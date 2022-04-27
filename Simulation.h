#include <iostream>
#include <fstream>
//#include <string>
#include "GenQueue.h"
#include "DoublyLinkedList.h"
#include "Student.h"
#include "Windows.h"
using namespace std;
//Creates Simulation class
class Simulation
{
public:
    Simulation();
    Simulation(int t);
    ~Simulation();

    void processFile(string file);
    void createSimulation();

    void updateWaitTime(GenQueue<Student*> *q);
    void updateIdleTime(Windows **w);


    void printStatistics();
    float meanStudentWaitTime();
    int medianStudentWaitTime();
    int maxStudentWaitTime();
    int studentOver10Min();

    float meanIdleTime();
    int maxIdleTime();
    int windowsOver5Min();



    GenQueue<Student*> *queue;
    Windows **w;
    GenQueue<int> *waitTimes;
    GenQueue<int> *idleTimes;
    GenQueue<int> *text;
    int worldClock = 0;
    int numOpenWindows = 0;
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
    int idle5Min;

};
//Default Constructor
Simulation::Simulation()
{
    queue = new GenQueue<Student*>();
    waitTimes = new GenQueue<int>();
    idleTimes = new GenQueue<int>();
}
//Default Destructor
Simulation::~Simulation()
{
}

void Simulation::processFile(string file) //takes in a file from the command line and sends data to genqueue
{
    text = new GenQueue<int>;
    string input = "";
    string line;
    // takes command line argument
    ifstream infile;
    infile.open(file);
    int value = 0;
    if (infile.is_open() && infile.good()) { // checks if file is good
        //cout << "File is now open!\nContains:\n";
        cout << "File is now open!"<<endl;
        string line = "";
        while (getline(infile, line)){
        value = stoi(line);
        text->insert(value);
        input += line;
        input += "\n";
    }
    } else {
        cout << "Failed to open file"<<endl;
    }
    createSimulation();
    infile.close();
}

void Simulation::createSimulation()
{
    cap = text->remove();
    cout<<cap<<endl;
    w = new Windows *[cap];
    for(int k = 0; k < cap; k++){
        w[k] = new Windows();
    }
    numOpenWindows = cap;
    time = text->remove();
    while(!(text->isEmpty()) || numOpenWindows != cap){
        cout<<"TOP OF MAIN LOOP"<<endl;
        //every loop is 1 minute passed/one tick on the world clock
        worldClock++;
        cout<<worldClock<<"  "<<time<<endl;
        if(worldClock == time){
            cout<<"TOP OF TIME LOOP"<<endl;
            if(!(text->isEmpty())){
                numberStudents = text->remove();
            }
            //adds the students to the queue with their wait times
            for(int j = 0; j < numberStudents; j++){
                if(!(text->isEmpty())){
                    Student *s = new Student(text->remove());
                    queue->insert(s);
                }

            }

            int c = 0;
            //loops through all windows
            while(c < cap){
                int count = 0;
                if(w[c]->isBusy()){
                    //decreases students needed time at the window by 1 because one minute has gone by
                    w[c]->decreseWindowTime();
                    //checks if student is finished using window
                    if(w[c]->timeNeeded() == 0){
                     w[c]->setEmpty();
                     numOpenWindows++;
                    }
                    cout<<"Window "<< c << " is busy"<<endl;
                }
                if(w[c]->isEmpty() && (!(queue->isEmpty()))){
                    cout << "top of empty loop" << endl;
                    //takes student out of queue

                    Student *stu = queue->remove();

                    //how long they have been waiting
                    waitTimes->insert(stu->getWaitTime());
                    //adds the idle time of the window to the list before a student fills it
                    idleTimes->insert(w[c]->getTimeEmpty());
                    //puts them at window c
                    w[c]->setBusy(stu);
                    numOpenWindows--;
                }
                c++;
            }

            //updates the idle time of the open windows
            updateIdleTime(w);
            //updates the wait time of the people in the queue
            updateWaitTime(queue);
            if(!(text->isEmpty())){
                time = text->remove();
            }

        }
        else{
            int p = 0;
            while(p < cap){
                cout<<"ALL WINDOWS FULL"<<endl;
                if(w[p]->isBusy()){
                    w[p]->decreseWindowTime();
                    //checks if student is finished using window
                    if(w[p]->timeNeeded() == 0){
                    //if student is finished then it sets the window to empty and number of open windows increases
                     w[p]->setEmpty();
                     numOpenWindows++;
                    }
                    cout<<"Window "<< p << " is busy"<<endl;
                }
                cout<<"before empty loop"<<endl;
                if(w[p]->isEmpty() && !(queue->isEmpty())){
                    cout<<"Inside empty window loop"<<endl;
                    //takes student out of queue
                    Student *stu = queue->remove();
                    //how long they have been waiting
                    waitTimes->insert(stu->getWaitTime());
                    //adds the idle time of the window to the list before a student fills it
                    idleTimes->insert(w[p]->getTimeEmpty());
                    //puts them at window c
                    w[p]->setBusy(queue->remove());
                    numOpenWindows--;
                }
                cout<<"after empty loop"<<endl;
                p++;
            }
            //updates the idle time of the open windows
            updateIdleTime(w);
            //updates the wait time of the people in the queue
            updateWaitTime(queue);
            //sets time to the next time
            if(!(text->isEmpty())){
                time = text->remove();
            }
        }
    }

    printStatistics();

}



void Simulation::updateIdleTime(Windows **w){
    for(int i = 0; i < cap; i++){
        if(w[i]->isEmpty()){
            w[i]->updateIdleTime();
        }
    }
}

//updates the wait time of the people in the queue
void Simulation::updateWaitTime(GenQueue<Student*> *q){
    int i = 0;
    while(i < q->getSize()){
        Student *s = q->remove();
        s->updateWindowTime();
        q->insert(s);
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

int Simulation::medianStudentWaitTime(){

}

int Simulation::maxStudentWaitTime(){
    studentMaxWait = 0;
    int count = 0;
    while(count <= waitTimes->getSize()){
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
    while(count <= idleTimes->getSize()){
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
//list sort function for median
