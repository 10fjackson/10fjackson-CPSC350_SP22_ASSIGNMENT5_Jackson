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
    GenQueue<int> *idleTimes;
    int worldClock = 0;
    int numOpenWindows = 0;
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
    numOpenWindows = cap;
    time = text[i++];
    while(i < text.length() || numOpenWindows != cap){
        //every loop is 1 minute passed/one tick on the world clock
        worldClock++;
        
        if(worldClock == time){

            numberStudents = text[i++];
            //adds the students to the queue with their wait times
            for(int j = 0; j < numberStudents; j++){
                Student *s = new Student(text[i++]);
                queue.insert(s);
                cout << queue.peak() << endl;
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
                    cout<<"window "<< c << " is busy"<<endl;
                }

                if(w[c]->isEmpty() && queue->!(isEmpty())){
                    //takes student out of queue
                    Student *stu = queue.remove();
                    //how long they have been waiting
                    waitTimes->insert(stu->getStudentWaitTime());
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
            time = text[i++];

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
                    cout<<"window "<< p << " is busy"<<endl;
                }

                if(w[c]->isEmpty() && queue->!(isEmpty())){
                    //takes student out of queue
                    Student *stu = queue.remove();
                    //how long they have been waiting
                    waitTimes->insert(stu->getStudentWaitTime());
                    //adds the idle time of the window to the list before a student fills it
                    idleTimes->insert(getTimeEmpty());
                    //puts them at window c
                    w[p]->setBusy(queue.remove());
                    numOpenWindows--;
                }
                p++;
            } 
            //updates the idle time of the open windows
            updateIdleTime(w);
            //updates the wait time of the people in the queue
            updateWaitTime(queue);
            //sets time to the next time
            time = text[i++];
        }
    }

}
//updates the idle time of the open windows
void updateIdleTime(Windows **w){
    for(int i = 0; i < cap; i++){
        if(w[i]->isEmpty()){
            w[i]->updateIdleTime();
        }
    }
}
//updates the wait time of the people in the queue
void Simulation::updateWaitTime(GenQueue<Student> *q){
    int l = 0;
    while(l < q->getSize()){
        Student *s = q->remove();
        s->updateWindowTime();
        q->insert(data);
        i++;
    }
}

