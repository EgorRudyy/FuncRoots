#include <iostream>
#include <math.h>

using namespace std;

double func(double x)
{
    return (x * x * x - x * x + 2);
}
double deriv(double x)
{

    return (3 * x * x - 2 * x);
}

class Solver {
private:
    double x, y;
public:
    double e = 0.001;
    Solver(double x1, double  y1) {
        this->x = x1;
        this->y = y1;
    }
    double getx1() { return x; }
    double gety1() { return y; }
    double setx1(double x1) { x = x1; }
    double sety1(double y1) { y = y1; }
    double Bisectrix(double(&func) (double x));
    double Tangent(double(&func) (double x), double(&deriv) (double x));
    double Chord(double(&func) (double x));
};


int main()
{
    Solver A(-100, 100);
    A.Tangent(func, deriv);
    A.Bisectrix(func);
    A.Chord(func);

}


double Solver::Bisectrix(double(&func) (double x)) {
    double a=-100, b=100;
    if (func(a) * func(b) >= 0)
    {
        cout << "You have not assumed right a and b" << endl;
        return 0;
    }

    double c = a;
    while ((b - a) >= e)
    {
        c = (a + b) / 2;

        if (func(c) == 0.0)
            break;

        else if (func(c) * func(a) < 0)
            b = c;
        else
            a = c;
    }
    cout << "Bisectrix.The value of root is : " << c << endl;
    return c;
}

double Solver::Tangent(double(&func) (double x), double(&deriv) (double x))
{
    double h;
    h = func(x) / deriv(x);
    while (abs(h) >= e)
    {
        h = func(x) / deriv(x);
        x = x - h;
    }
    cout << "Tangent.The value of the root is : " << x << endl;
    return x;

}

double Solver::Chord(double(&func) (double x)) {
    while (abs(y - x) >= e)
    {
        y = x - (x - y) * func(x) / (func(x) - func(y));
        x = y + (y - x) * func(y) / (func(y) - func(x));
    }
    cout << "The value of the root is : " << x << endl;
    return x;
}