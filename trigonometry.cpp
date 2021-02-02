#include <iostream>
#include <math.h>
using namespace std;

// Code to calculate the hypetenuse and Sin, Cos, Tan, Csc, Sec, and Cot of a right triangle.

// oppsite = y adjacent= x
void trigonometricFunction (double x, double y, double h) {
    double sinAnswer, cosAnswer, tanAnswer, cscAnswer, secAnswer, cotAnswer;

    sinAnswer = sin(y / h);
    cosAnswer = cos(x / h);
    tanAnswer = tan(y / x);
    cscAnswer = 1 / sinAnswer;
    secAnswer = 1 / cosAnswer;
    cotAnswer = 1 / tanAnswer;

    cout << "Hypotenuse: " << h << endl;
    cout << "Sin: " << sinAnswer << endl;
    cout << "Cos: " << cosAnswer << endl;
    cout << "Tan: " << tanAnswer << endl;
    cout << "Csc: " << cscAnswer << endl;
    cout << "Sec: " << secAnswer << endl;
    cout << "Cot: " << cotAnswer << endl;
}

// Function to return the hypotenuse of the
// right angled triangle
double findHypotenuse(double x, double y)
{
    double h = sqrt((x * x) + (y * y));
    return h;
}

int main()
{
    double x, y, h;

    cout << "Enter the adjacent side of the triangle: ";
    cin>>x;
    cout << "Enter the opposite side of the triangle: ";
    cin>>y;
    cout << endl;

    h = findHypotenuse(x, y);
    trigonometricFunction(x,y,h);

    return 0;
}
