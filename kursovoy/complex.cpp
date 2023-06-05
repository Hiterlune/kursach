#include <iostream>
#include "baseclass.h"
#include "pentagon.h"
#include "circle.h"
#include "complex.h"
using namespace std;

ComplexFigure::ComplexFigure(Circle& circle, Pentagon& pentagon) : circle(circle), pentagon(pentagon) {

    if (!((pentagon.getA() * sqrt(5) * sqrt(5 + 2 * sqrt(5)) / 10) < (float)circle.getR() + 1 && (pentagon.getA() * sqrt(5) * sqrt(5 + 2 * sqrt(5)) / 10) > (float)circle.getR() - 1)) {

        throw Exception("Error: радиусы фигур не совпадают. Окружность не вписывается в пятиугольник");
    }
    if (circle.getX() != pentagon.getX() || circle.getY() != pentagon.getY()) {
        throw Exception("Error: координаты центров фигур не совпадают. Окружность не вписывается в пятиугольник");
    }
};
void ComplexFigure::Draw()
{
    pentagon.Draw();
    circle.Draw();
}
void ComplexFigure::Stash()
{
    pentagon.Stash();
    circle.Stash();
}
void ComplexFigure::Displace(int xNew, int yNew)
{
    pentagon.Displace(xNew, yNew);
    circle.Displace(xNew, yNew);

}