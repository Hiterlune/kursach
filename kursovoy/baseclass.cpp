#include "baseclass.h"
#include "exception.h"
#include <iostream>
using namespace std;

Figure::Figure(int x, int y, int r, COLORREF color, COLORREF line) : x(x), y(y), r(r), color(color), line(line) {
    
    hwnd = GetConsoleWindow();
    hdc = GetDC(hwnd);        
    GetClientRect(hwnd, &rt); 
};

