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
    void updateTimeEmpty(int t){
        timeEmpty = t;
    }
    int getTimeEmpty(){
        return timeEmpty;
    }
    void setBusy(Student *s){
        isEmpty = false;
        stu = s;
    }
    void setEmpty(){
        isEmpty = true;
        stu = NULL;
    }
    bool isBusy(){
        if(isEmpty){
            return false;
        }
        else{
            return true;
        }
    }
    bool isEmpty(){
        return isEmpty;
    }
    int timeNeeded(){
        return stu->getWindowTime();
    }
    void decreseWindowTime(){
        stu->updateWindowTime();
    }

#endif