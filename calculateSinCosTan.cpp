#include <iostream>
#include <math.h>
using namespace std;

//const double pi = 3.14159265359;

// Code to calculate the Sin, Cos, and Tan given the angle in radians.
void calculateSin(double angle) {
    double degree = angle * (180 / M_PI);

    cout << "sin(x) = " << sin(degree) << endl;
}

void calculateCos(double angle) {
    double degree = angle * (180 / M_PI);

    cout << "cos(x) = " << cos(degree) << endl;
}

void calculateTan(double angle) {
    double degree = angle * (180 / M_PI);

    cout << "tan(x) = " << tan(degree) << endl;
}

int main(){
    double angle;
    int choice;

    cout << "Enter the angle in radians: ";
    cin>>angle;
    cout << endl;
    cout << "What trigonometric function would you like to use?";
    cout << endl;
    cout << "1 - sin" << endl;
    cout << "2 - cos" << endl;
    cout << "3 - tan" << endl;
    cout << "Answer: ";
    cin>>choice;
    cout << endl;

    switch (choice) {
        case 1:
            calculateSin(angle);
            break;
        case 2:
            calculateCos(angle);
            break;
        case 3:
            calculateTan(angle);
            break;
        default:
            cout << "Invalid Answer!" << endl;
    }

    return 0;
}
