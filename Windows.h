#ifndef WINDOWS_H
#define WINDOWS_H
#include <iostream>
using namespace std;

class Windows{
public:
    Windows();
    Windows(Student *s);
    ~Windows();
    void updateTimeEmpty();
    int getIdleTime();
    void setBusy(Student *s);
    void setEmpty();
    bool isEmpty();
    int timeNeeded();

private:
   int timeEmpty;
   bool isEmpty;
   Student *stu;
};

    Windows(){
        timeEmpty = 0;
        isEmpty = true;
        stu = NULL;
    }
    Windows(Student *s){
        timeEmpty = 0;
        isEmpty = true;
        stu = s;
    }
    ~Windows(){

    }
    void Windows::updateTimeEmpty(int t){
        timeEmpty = t;
    }
    int Windows::getTimeEmpty(){
        return timeEmpty;
    }
    void Windows::setBusy(Student *s){
        isEmpty = false;
        stu = s;
    }
    void Windows::setEmpty(){
        isEmpty = true;
        stu = NULL;
    }
    bool Windows::isBusy(){
        if(isEmpty){
            return false;
        }
        else{
            return true;
        }
    }
    bool Windows::isEmpty(){
        return isEmpty;
    }
    int Windows::timeNeeded(){
        return stu->getWindowTime();
    }
    void Windows::decreseWindowTime(){
        stu->updateWindowTime();
    }
    int Windows::getStudentWaitTime(){
        return stu->getWaitTime();
    }

#endif