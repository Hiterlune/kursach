#include <iostream>
#include "circle.h"
#include "exception.h"
using namespace std;

Circle::Circle(int x, int y, int r, COLORREF color, COLORREF line) : Figure(x, y, r, color, line) {
    if ((x - r) < 0 || (y - r) < 0) {
        throw Exception("Error: ������� ������������� ����������");
    }
    if (r <= 0) {
        throw Exception("Error: � ���������� ������ ������������ ������");
    }
    if (x - r < rt.left || x + r > rt.right || y - r < rt.top || y + r > rt.bottom) {
        throw Exception("Error: ���������� (x: " + to_string(x) + " y: " + to_string(y) + " r: " + to_string(r) + ") ������� �� ������� �������");
    }
};

void Circle::Draw()
{
    HPEN   pen = CreatePen(PS_SOLID, 2, line);
    HBRUSH brush = CreateSolidBrush(color);
    SelectObject(hdc, pen);
    SelectObject(hdc, brush);
    Ellipse(hdc, x - r, y - r, x + r, y + r);

    DeleteObject(pen);
    DeleteObject(brush);


};

void Circle::Stash()
{
    HPEN   pen = CreatePen(PS_SOLID, 2, RGB(59, 120, 254));
    HBRUSH brush = CreateSolidBrush(RGB(59, 120, 254));
    SelectObject(hdc, pen);
    SelectObject(hdc, brush);
    Ellipse(hdc, x - r, y - r, x + r, y + r);

    DeleteObject(pen);
    DeleteObject(brush);
};
void Circle::Displace(int xNew, int yNew)
{
    if (x + xNew - r < rt.left || x + xNew + r > rt.right || y + yNew - r < rt.top || y + yNew + r > rt.bottom) {
        throw Exception("Error: ���������� (x: " + to_string(x) + " y: " + to_string(y) + " r: " + to_string(r) + ") ��� ����������� ������� �� ������� �������");
    }
    x += xNew;
    y += yNew;
    Stash();
    Draw();
}

int Circle::getX()
{
    return x;
}

int Circle::getY()
{
    return y;
}

int Circle::getR()
{
    return r;
}
