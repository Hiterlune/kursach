#pragma once
#include <iostream>
#include <windows.h>
#include <windowsx.h>
#include "baseclass.h"
#include "pentagon.h"
#include "circle.h"
#include "exception.h"
using namespace std;

class ComplexFigure : public Figure {
private:
    Circle circle;
    Pentagon pentagon;
public:
    ComplexFigure(Circle& circle, Pentagon& pentagon);
    void Draw() override;
    void Stash() override;
    void Displace(int, int) override;
};