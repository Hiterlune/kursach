// Курсовой проект выполнен на первом курсе программной инженерии 
// группа 22ВП2, Родионов Иван
// ПГУ, Пенза 2023

#include <iostream>
#include "exception.h"
#include "complex.h"
#include "stack.h"

using namespace std;
const int NotUsed = system("color 9F");


int main() {

    setlocale(LC_ALL, "RUS");
    SetConsoleTitle((LPCWSTR)L"project22VP2_22");
    try {
        Pentagon pent(100, 200, 80, RGB(92, 0, 100), RGB(0, 0, 0));
        Circle circ(100, 200, 65, RGB(29, 153, 141), RGB(0, 0, 0));
        ComplexFigure comp(circ, pent);

        StackAsList st;
        st.AddtoStack(&comp);
        st.ShowOutStack();
    }
    catch (Exception ex) {
        cout << ex.getErr() << endl;
    }
    Sleep(3000);
    COORD cursor = { 1, 20 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}