#include "eq2.h"
#include <iostream>

using namespace std;

Eq2::Eq2() {
    a = 0;
    b = 0;
    c = 0;
    D = 0;
}

Eq2::Eq2(double a, double b, double c) {
    this->a = a; this->b = b; this->c = c;
    D = b * b - 4 * a * c;
}

void Eq2::set(double a, double b, double c) {
    this->a = a; this->b = b; this->c = c;
    D = b * b - 4 * a * c;
}

double Eq2::find_X() {
    if (D < 0) {
        cout << "Корней нет" << endl;
        return 0;
    }
    else {
        if (D == 0) {
            double x = (-b - sqrt(D)) / (2 * a);
            cout << "Корень один: " << x << endl;
            return x;
        }
        else {
            cout << "Корней 2, наибольший: ";
            
            double x1 = (-b - sqrt(D)) / (2 * a);
            double x2 = (-b + sqrt(D)) / (2 * a);
            
            if (x1 > x2) {
                cout << x1 << endl;
                return x1;
            }
            else {
                cout << x2 << endl;
                return x2;
            }
        }
    }
}

double Eq2::find_Y(double x) {
    return a * x * x + b * x + c;
}

Eq2 operator +(Eq2& eq2_1, Eq2& eq2_2) {
    Eq2 eq2_res;
    eq2_res.set(eq2_1.a + eq2_2.a, eq2_1.b + eq2_2.b, eq2_1.c + eq2_2.c);
    return eq2_res;
}

ostream& operator <<(ostream &out, Eq2 eq) {
    cout << eq.a << " * x^2 + " << eq.b << " * x + " << eq.c << endl;
    return out;
}
