#pragma once
#include <iostream>
#include <stack>
#include <list>
#include "baseclass.h"

using namespace std;

class StackAsList {
private:
    stack<Figure*, list<Figure*>>stack;
public:
    void AddtoStack(Figure* figure);

    void DeleteOutStack();

    void ClearStack();

    void ShowOutStack();
};