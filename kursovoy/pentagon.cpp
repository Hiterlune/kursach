#include "pentagon.h"
#include "cmath"
#include "exception.h"
#include <iostream>
using namespace std;

Pentagon::Pentagon(int x, int y, int r, COLORREF color, COLORREF line) : Figure(x, y, r, color, line) {
    a = 2 * r * sin(3.14159 / 5);
    int x1 = x + r * cos(18 * 3.14159 / 180);
    int y1 = y - r * sin(18 * 3.14159 / 180);
    int x2 = x + r * cos(90 * 3.14159 / 180);
    int y2 = y - r * sin(90 * 3.14159 / 180);
    int x3 = x + r * cos(162 * 3.14159 / 180);
    int y3 = y - r * sin(162 * 3.14159 / 180);
    int x4 = x + r * cos(234 * 3.14159 / 180);
    int y4 = y - r * sin(234 * 3.14159 / 180);
    int x5 = x + r * cos(306 * 3.14159 / 180);
    int y5 = y - r * sin(306 * 3.14159 / 180);

    points[0] = { x1, y1 };
    points[1] = { x2, y2 };
    points[2] = { x3 ,y3 };
    points[3] = { x4 ,y4 };
    points[4] = { x5 ,y5 };

    if (r <= 0) {
        throw Exception("Error: у пятиугольника введен неправильный радиус");
    }
    if (x1 < rt.left || x3 > rt.right || y2 < rt.top || y4 > rt.bottom || x1 < 0 || y2 < 0) {
        throw Exception("Error: пятиугольник (x: " + to_string(x) + " y: " + to_string(y) + " r: " + to_string(r) + ") выходит за пределы консоли");
    }
};

void Pentagon::Draw()
{
    HPEN   pen = CreatePen(PS_SOLID, 2, line);
    HBRUSH brush = CreateSolidBrush(color);
    SelectObject(hdc, pen);
    SelectObject(hdc, brush);
    Polygon(hdc, points, 5);

    DeleteObject(pen);
    DeleteObject(brush);
};
void Pentagon::Stash()
{

    HPEN   pen = CreatePen(PS_SOLID, 2, RGB(59, 120, 254));
    HBRUSH brush = CreateSolidBrush(RGB(59, 120, 254));
    SelectObject(hdc, pen);
    SelectObject(hdc, brush);
    Polygon(hdc, points, 5);

    DeleteObject(pen);
    DeleteObject(brush);

};
void Pentagon::Displace(int xNew, int yNew)
{
    x += xNew;
    y += yNew;

    int x1 = x + r * cos(18 * 3.14159 / 180);
    int y1 = y - r * sin(18 * 3.14159 / 180);
    int x2 = x + r * cos(90 * 3.14159 / 180);
    int y2 = y - r * sin(90 * 3.14159 / 180);
    int x3 = x + r * cos(162 * 3.14159 / 180);
    int y3 = y - r * sin(162 * 3.14159 / 180);
    int x4 = x + r * cos(234 * 3.14159 / 180);
    int y4 = y - r * sin(234 * 3.14159 / 180);
    int x5 = x + r * cos(306 * 3.14159 / 180);
    int y5 = y - r * sin(306 * 3.14159 / 180);

    points[0] = { x1, y1 };
    points[1] = { x2, y2 };
    points[2] = { x3 ,y3 };
    points[3] = { x4 ,y4 };
    points[4] = { x5 ,y5 };

    if (x1 < rt.left || x3 > rt.right || y2 < rt.top || y4 > rt.bottom || x1 < 0 || y2 < 0) {
        throw Exception("Error: пятиугольник (x: " + to_string(x) + " y: " + to_string(y) + " r: " + to_string(r) + ") при перемещении выходит за пределы консоли");
    }


    Stash();
    Draw();
}
int Pentagon::getX()
{
    return x;
}
int Pentagon::getY()
{
    return y;
}
float Pentagon::getA()
{
    return a;
}

