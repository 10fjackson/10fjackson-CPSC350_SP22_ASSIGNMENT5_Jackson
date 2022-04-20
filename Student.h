
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

class Student
{
public:
    Student();
    Student(int t);
    ~Student();
    void updateWindowTime();
    int getWindowTime();
    void updateWaitTime();
    int getWaitTime();
    void setWindowTime(int t);


private:
   int windowTime;
   int waitTime;
};
    
    Student::Student(){
        windowTime = 0;
        waitTime = 0;
    }

    Student::Student(int t){
        windowTime = t;
        waitTime = 0;
    }

    Student::~Student(){

    }

    void Student::updateWindowTime(){
        windowTime++;
    }

    int Student::getWindowTime(){
        return windowTime;
    }

    void Student::updateWaitTime(){
        waitTime++;
    }

    int Student::getWaitTime(){
        return waitTime;
    }

    void Student::setWindowTime(int t){
        windowTime = t;
    }
    #endif