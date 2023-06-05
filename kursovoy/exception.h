#pragma once

#include <iostream>
#include <string>
using namespace std;

class Exception {
private:
    string error;
public:
    Exception(string fail) { error = fail; }
    string getErr() { return error; }
};