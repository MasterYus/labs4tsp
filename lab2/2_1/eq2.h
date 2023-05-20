#pragma once
#include <iostream>

using namespace std;

class Eq2 {

private:
    double a, b, c; // коэффициенты уравнения
    double D;       // дискриминант

    friend Eq2 operator +(Eq2& eq2_1, Eq2& eq2_2);
    friend ostream& operator <<(ostream& out, Eq2 eq);

public:
    Eq2();
    Eq2(double a, double b, double c);
    void set(double a, double b, double c);
    double find_X();
    double find_Y(double x);

}; // end of Eq2
