#pragma once
#include "baseclass.h"
#include <iostream>
using namespace std;

class Pentagon : public Figure {
private:
    float a; 
    POINT points[5];
public:
    Pentagon(int x = 0, int y = 0, int r = 0, COLORREF color = RGB(255, 255, 255), COLORREF line = RGB(0, 0, 0));
    void Draw() override;
    void Stash() override;
    void Displace(int xNew, int yNew) override;
    int getX();
    int getY();
    float getA();
};
