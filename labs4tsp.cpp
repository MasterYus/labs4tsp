#include <iostream>
#include <map>
#include "lab1/1_1/triangle.h"
#include "lab1/1_2/circle.h"
#include "lab1/1_3/figure.h"
#include "lab2/2_1/eq2.h"
#include "lab2/2_3/rational.h"
#include "lab3/3_1/cone.h"
#include "lab3/3_2/frustum.h"
#include "lab3/3_3/ocean.h"
#include "lab3/3_3/sea.h"
#include "lab3/3_3/bay.h"

constexpr auto _DELIMITER = "───────────────\n";

using namespace std;

// 1st practice(/lab1)
void task_1_1();
void task_1_2();
void task_1_3();

// 2nd practice(/lab2)
void task_2_1();
void task_2_2();
void task_2_3();

// 3rd practice(/lab3)
void task_3_1();
void task_3_2();
void task_3_3();

int main()
{
    string input;

    setlocale(LC_ALL, "Russian");

    while (true) {
        system("cls");
        cout << "Введите номер задания: ";
        getline(cin, input);
        if (input == "1_1") {
            task_1_1();
        } else if (input == "1_2") {
            task_1_2();
        } else if (input == "1_3") {
            task_1_3();
        } else if (input == "2_1") {
            task_2_1();
        } else if (input == "2_2") {
            task_2_2();      
        } else if (input == "2_3") {
            task_2_3();
        } else if (input == "3_1") {
            task_3_1();
        } else if (input == "3_2") {
            task_3_2();
        } else if (input == "3_3") {
            task_3_3();
        } else {
            continue;
        }
        cout << "Нажмите любую клавишу..." << endl;
        getchar();
    }
    return 0;
}

void task_1_1() {
    Triangle triangles[3];
    double a, b, c;

    for (int i = 0; i < 3; i++) {
        cout << "\nВведите длины сторон a, b и c треугольника № " << i + 1 << " через пробел: ";
        cin >> a >> b >> c;
        triangles[i].set(a, b, c);

        if (!(triangles[i].exst_tr())) {
            cout << "\nТреугольника с такими сторонами не существует, попробуйте ещё раз!" << endl;
            i--;
        }
        else {
            cout << "\nТреугольник № " << i + 1 << endl;
            triangles[i].show();

            cout << "Периметр треугольника: " << triangles[i].perimetr() << endl;
            cout << "Площадь треугольника: " << triangles[i].square() << endl;
        }
    }
}

void task_1_2() {
    Circle* circles[3];
    double r, x_center, y_center;
    double a, b, c;

    for (int i = 0; i < 3; i++) {
        cout << "\nВведите радиус окружности № " << i + 1 << " и координаты x и y её центра через пробел: ";
        cin >> r >> x_center >> y_center;
        circles[i] = new Circle(r, x_center, y_center);
    }

    cout << "\nВведите через пробел стороны a, b и с треугольника для проверки: ";
    cin >> a >> b >> c;

    for (int i = 0; i < 3; i++) {
        cout << "\nОкружность № " << i + 1 << endl;

        cout << "Введите новые значения радиуса окружности и координат x и y её центра через пробел: ";
        cin >> r >> x_center >> y_center;
        circles[i]->set_circle(r, x_center, y_center);

        cout << "Площадь: " << circles[i]->square() << endl;

        if (circles[i]->triangle_around(a, b, c))
            cout << "Данная окружность может быть описана вокруг указанного треугольника." << endl;
        else
            cout << "Данная окружность не может быть описана вокруг указанного треугольника." << endl;

        if (circles[i]->triangle_in(a, b, c))
            cout << "Данная окружность может быть вписана в указанный треугольник." << endl;
        else
            cout << "Данная окружность не может быть вписана в указанный треугольник." << endl;

        cout << "Введите через пробел радиус, координаты x и y центра ещё одной окружности для проверки на пересечение: ";
        cin >> r >> x_center >> y_center;
        if (circles[i]->check_circle(r, x_center, y_center)) {
            cout << "Окружности пересекаются." << endl;
        }
        else {
            cout << "Окружности не пересекаются." << endl;
        }
    }
}

void task_1_3() {
    Figure* figures[3];
    double x1, x2, x3, x4;
    double y1, y2, y3, y4;

    for (int i = 0; i < 3; i++) {
        cout << endl;
        cout << "Введите координаты вершины A четырёхугольника № " << i + 1 << " через пробел: ";
        cin >> x1 >> y1;
        cout << "Введите координаты вершины B четырёхугольника № " << i + 1 << " через пробел: ";
        cin >> x2 >> y2;
        cout << "Введите координаты вершины C четырёхугольника № " << i + 1 << " через пробел: ";
        cin >> x3 >> y3;
        cout << "Введите координаты вершины D четырёхугольника № " << i + 1 << " через пробел: ";
        cin >> x4 >> y4;

        figures[i] = new Figure(x1, y1, x2, y2, x3, y3, x4, y4);

        cout << "\nЧетырёхугольник № " << i + 1 << endl;

        figures[i]->show();

        if (figures[i]->is_prug())
            cout << "Является четырёхугольником." << endl;
        else
            cout << "Не является четырёхугольником." << endl;

        if (figures[i]->is_rectangle())
            cout << "Является прямоугольником." << endl;
        else
            cout << "Не является прямоугольником." << endl;

        if (figures[i]->is_romb())
            cout << "Является ромбом." << endl;
        else
            cout << "Не является ромбом." << endl;

        if (figures[i]->is_square())
            cout << "Является квадратом." << endl;
        else
            cout << "Не является квадратом." << endl;

        if (figures[i]->is_in_circle())
            cout << "Может быть вписан в окружность." << endl;
        else
            cout << "Не может быть вписан в окружность." << endl;

        if (figures[i]->is_out_circle())
            cout << "В него может быть вписана окружность." << endl;
        else
            cout << "В него не может быть вписана окружность." << endl;
    }
}

void task_2_1() {
    double a, b, c;
    cout << "Введите коэффициенты квадратного уравнения через пробел: ";
    cin >> a >> b >> c;

    Eq2 exmpl(a, b, c);
    exmpl.find_X();

    double x;
    cout << "Введите значение x, для которого необходимо вычислить значение квадратного многочлена: ";
    cin >> x;
    cout << "Значение квадратного многочлена: " << exmpl.find_Y(x) << endl;

    cout << "Введите коэффициенты ещё одного квадратного уравнения через пробел: ";
    cin >> a >> b >> c;
    Eq2 exmpl_2(a, b, c);

    Eq2 result = exmpl + exmpl_2;
    cout << "Результат сложения двух уравнений: " << result << endl;
}

void task_2_2() {
    int a, b;

    int n;
    cout << "Введите количество элементов массива: ";
    cin >> n;

    Rational* rationals = new Rational[n];

    for (int i = 0; i < n; i++) {
        do
        {
            cout << "\nВведите числитель и знаменатель дроби № " << i + 1 << " через пробел: ";
            cin >> a >> b;
            rationals[i].set(a, b);
        } while (b == 0);

        rationals[i].show();
    }

    delete[] rationals;
}

void task_2_3() {
    int a, b;

    int n;
    cout << "Введите количество элементов массива: ";
    cin >> n;

    Rational* rationals = new Rational[n];

    for (int i = 0; i < n; i++) {
        do
        {
            cout << "\nВведите числитель и знаменатель дроби № " << i + 1 << " через пробел: ";
            cin >> a >> b;
            rationals[i].set(a, b);
        } while (b == 0);

        rationals[i].show();
    }

    Rational r;
    int r1, r2;
    cout << "\nУкажите через пробел номера дробей, с которыми необходимо выполнить операции: ";
    cin >> r1 >> r2;
    cout << "\nВыбранные дроби: " << endl;
    cout << "r1 = "; rationals[r1 - 1].show();
    cout << "r2 = "; rationals[r2 - 1].show();

    cout << "\nСумма дробей = ";
    r = rationals[r1 - 1] + rationals[r2 - 1];
    r.show();

    cout << "\nРазность дробей = ";
    r = rationals[r1 - 1] - rationals[r2 - 1];
    r.show();

    cout << "\nПостфиксный инкремент числителя первой дроби: ";
    rationals[r1 - 1]++;
    rationals[r1 - 1].show();

    cout << "\nПрефиксный инкремент числителя второй дроби: ";
    ++rationals[r2 - 1];
    rationals[r2 - 1].show();

    if (rationals[r1 - 1] == rationals[r2 - 1]) cout << "\nДроби равны." << endl;
    else cout << "\nДроби не равны." << endl;

    if (rationals[r1 - 1] > rationals[r2 - 1]) cout << "\nПервая дробь больше второй." << endl;
    else cout << "\nПервая дробь не больше второй." << endl;

    cout << "\nПрисвоим второй дроби значение первой дроби. Результат: ";
    rationals[r2 - 1] = rationals[r1 - 1];
    rationals[r2 - 1].show();

    delete[] rationals;
}

void task_3_1() {
    Cone c1(3, 7);

    cout << "\nКонус № 1: " << c1;
    cout << "Площадь поверхности = " << c1.area() << endl;
    cout << "Объём = " << c1.volume() << endl;


    Cone c2(1, 2, 3, 5, 10);

    cout << "\nКонус № 2: " << c2;
    cout << "Площадь поверхности = " << c2.area() << endl;
    cout << "Объём = " << c2.volume() << endl;


    Cone* c3 = new Cone;
    double x, y, z, r, h;

    cout << "\nВведите координаты центра конуса № 3 через пробел: ";
    cin >> x >> y >> z;
    cout << "Введите радиус конуса № 3: ";
    cin >> r;
    cout << "Введите высоту конуса № 3: ";
    cin >> h;

    c3->setCoordinate(x, y, z);
    c3->setRadius(r);
    c3->setHeight(h);

    cout << "\nКонус № 3: " << *c3;
    cout << "Площадь поверхности = " << c3->area() << endl;
    cout << "Объём = " << c3->volume() << endl;


    Cone* cones[2];

    for (int i = 0; i < 2; i++) {
        cout << "\nВведите координаты центра конуса № " << i + 4 << " через пробел: ";
        cin >> x >> y >> z;
        cout << "Введите радиус конуса № " << i + 4 << ": ";
        cin >> r;
        cout << "Введите высоту конуса № " << i + 4 << ": ";
        cin >> h;

        cones[i] = new Cone(x, y, z, r, h);

        cout << "\nКонус № " << i + 4 << ": " << *cones[i];
        cout << "Площадь поверхности = " << cones[i]->area() << endl;
        cout << "Объём = " << cones[i]->volume() << endl;
    }
}

void task_3_2() {
    Frustum f1(5, 10, 7);

    cout << "\nУсечённый конус № 1: " << endl << f1;
    cout << "Площадь поверхности = " << f1.area() << endl;
    cout << "Объём = " << f1.volume() << endl;


    Frustum f2(2, 4, 3, 8, 16, 8);

    cout << "\nУсечённый конус № 2: " << endl << f2;
    cout << "Площадь поверхности = " << f2.area() << endl;
    cout << "Объём = " << f2.volume() << endl;


    Cone c(1, 2, 3, 10, 15);
    Frustum f3_1(c, 8);
    Frustum f3_2(c, 4);

    cout << "\nУсечённый конус № 3.1: " << endl << f3_1;
    cout << "Площадь поверхности = " << f3_1.area() << endl;
    cout << "Объём = " << f3_1.volume() << endl;

    cout << "\nУсечённый конус № 3.2: " << endl << f3_2;
    cout << "Площадь поверхности = " << f3_2.area() << endl;
    cout << "Объём = " << f3_2.volume() << endl;

    cout << "\nСравним усечённые конусы №№ 3.1 и 3.2:";
    map<string, bool> comparisons = f3_1.compare(f3_2);

    cout << endl;
}

void task_3_3() {
    Ocean ocean1("Тихий", "9сш157зд", 14750000, 1225);
    Ocean ocean2("Северный_Ледовитый", "90сш_0вд", 178684000, 3984);
    Ocean ocean3("", "", 0, 0);

    Sea sea1("Лаптевых", "76сш_125вд", 672000, 3385, ocean2);
    Sea sea2("Каспийское", "42сш_51вд", 390000, 1025);
    Sea sea3("Балтийское", "58сш_20вд", 419000, 470);
    Sea sea4("", "", 0, 0);

    Bay bay1("Ботнический залив", "62сш_19вд", 117000, 295,
        sea3.getName(), sea3.getLocation(), sea3.getArea(), sea3.getDepth(),
        ocean3.getName(), ocean3.getLocation(), ocean3.getArea(), ocean3.getDepth());

    bay1.show(); cout << _DELIMITER;

    Bay bay2("Авачинский залив", "52сш_158вд", 2400, 20,
        sea4.getName(), sea4.getLocation(), sea4.getArea(), sea4.getDepth(),
        ocean1.getName(), ocean1.getLocation(), ocean1.getArea(), ocean1.getDepth());

    bay2.show(); cout << _DELIMITER;

    Bay bay3("Оленёкский залив", "73сш_122вд", 470, 15,
        sea1.getName(), sea1.getLocation(), sea1.getArea(), sea1.getDepth(),
        ocean2.getName(), ocean2.getLocation(), ocean2.getArea(), ocean2.getDepth());

    bay3.show(); cout << _DELIMITER;

    ocean1.show(); cout << _DELIMITER;
    ocean2.show(); cout << _DELIMITER;

    sea1.show(); cout << _DELIMITER;
    sea2.show(); cout << _DELIMITER;
    sea3.show(); cout << _DELIMITER;
}
