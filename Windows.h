#ifndef WINDOWS_H
#define WINDOWS_H
#include "Student.h"
using namespace std;
class Windows{
public:
    Windows();
    Windows(Student *s);
    ~Windows();
    void updateTimeEmpty(int t);
    int getIdleTime();
    void setBusy(Student *s);
    void setEmpty();
    bool isEmpty();
    int timeNeeded();
    int getTimeEmpty();
    bool isBusy();
    void decreaseWindowTime();
    int getStudentWaitTime();
    void updateIdleTime();

private:
   int timeEmpty;
   bool isOpen;
   Student *stu;
};

Windows::Windows(){
    timeEmpty = 0;
    isOpen = true;
    stu = NULL;
}

Windows::Windows(Student *s){
    timeEmpty = 0;
    isOpen = true;
    stu = s;
}

Windows::~Windows(){

    }
void Windows::updateTimeEmpty(int t){
    timeEmpty = t;
}

int Windows::getTimeEmpty(){
    return timeEmpty;
}

void Windows::setBusy(Student *s){
    isOpen = false;
    stu = s;
}
void Windows::setEmpty(){
    isOpen = true;
    stu = NULL;
}

bool Windows::isBusy(){
        if(isOpen){
            return false;
        }
        else{
            return true;
        }
    }
bool Windows::isEmpty(){
        return isOpen;
}

int Windows::timeNeeded(){
        return stu->getWindowTime();
}

void Windows::decreaseWindowTime(){
        stu->updateWindowTime();
}

void Windows::updateIdleTime(){
    timeEmpty++;
}
int Windows::getStudentWaitTime(){
        return stu->getWaitTime();

}

#endif
