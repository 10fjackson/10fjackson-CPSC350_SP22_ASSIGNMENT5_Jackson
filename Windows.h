#ifndef WINDOWS_H
#define WINDOWS_H
#include <iostream>
using namespace std;

class Windows{
public:
    Windows();
    Windows(Student *s)
    ~Windows();
    

private:
   int timeEmpty;
   bool isEmpty;
   Student *stu;
};
