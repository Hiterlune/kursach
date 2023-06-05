#include <iostream>
#include <cmath>
#include <stack>
#include <list>
#include "stack.h"
#include "exception.h"
using namespace std;

void StackAsList::AddtoStack(Figure* figure)
{
    stack.push(figure);
}
void StackAsList::DeleteOutStack()
{
    if (!stack.empty()) {
        stack.pop();
    }
    else {
        throw Exception("Error: Стек пуст");
    }
}
void StackAsList::ClearStack()
{
    int size = stack.size();
    if (!stack.empty()) {
        for (int i = 0; i < size; i++)
        {
            stack.pop();
        }
    }
    else {
        throw Exception("Error: Стек пуст");
    }
}
void StackAsList::ShowOutStack()
{
    int size = stack.size();
    if (!stack.empty()) {
        for (int i = 0; i < size; i++)
        {
            stack.top()->Draw();
            stack.pop();
        }
    }
    else {
        throw Exception("Error: Стек пуст");
    }
};
