#ifndef WINDOWS_H
#define WINDOWS_H
#include <iostream>
using namespace std;

class Windows{
public:
    Windows();
    Windows(int windows);
    ~Windows();

    void setWindows(int windows);
    int getWindowsOpen();
    bool isWindowOpen();
    void updateWindowsOpen();

    void updateTime();
    int getTime();
    void setTime(int t);

    void setNumberStudent(int students);
    int getNumberStudent();



private:
   int timeEmpty;
   bool isEmpty;
   Student *stu;
   int numberWindows;
   int numberWindowsOpen;
   int numberStudent;
   int windowTime;
};

Windows::Windows(){
    numberWindows = 0;
    numberWindowsOpen = 0;
}

Windows::Windows(int windows){
    numberWindows = windows;
    numberWindowsOpen = windows;
}

Windows::~Windows(){

}

void Windows::setWindows(int windows){
    numberWindows = windows;
    numberWindowsOpen = windows;
}

int Windows::getWindowsOpen(){
    return numberWindowsOpen;
}

bool Windows::isWindowOpen(){
    if(numberWindowsOpen == 0){
        return false;
    } else {
        return true;
    }
}

void Windows::updateWindowsOpen(){
    numberWindowsOpen--;
}

void Windows::setTime(int t){
    windowTime = t;
}

void Windows::updateTime(){
    windowTime++;
}

int Windows::getTime(){
    return windowTime;
}

void Windows::setNumberStudent(int students){
    numberStudent = students;
}

int Windows::getNumberStudent(){
    return numberStudent;
}

#endif
