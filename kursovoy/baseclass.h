#pragma once
#include <iostream>
#include <cmath>
#include <windows.h>
#include <windowsx.h>
using namespace std;

class Figure { 
protected:
    int x, y, r;
    HWND hwnd;
    HDC hdc;
    RECT rt; 
    COLORREF color;
    COLORREF line;
public:
    virtual void Draw() = 0; 
    virtual void Stash() = 0; 
    virtual void Displace(int xNew, int yNew) = 0; 
    Figure(int x = 0, int y = 0, int r = 0, COLORREF color = RGB(255, 255, 255), COLORREF line = RGB(0, 0, 0));
};
