#ifndef WINDOWS_H
#define WINDOWS_H
#include <iostream>
using namespace std;

class Windows{
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