#include <iostream>
#include <cmath>
#include <iomanip>
#include "metode.h"
using namespace std;

static double functionNR(double a, double n, double b, double c, double x){
    return (a * pow(x, n)) + (b * x) + c;
}  

static double derivative(double a, double n, double b, double x){
    return (a * n * pow(x, n - 1)) + b;
}

static void showFunctionNR(double a, double n, double b, double c){
    cout << "\nFungsi f(x) = " << a << "x^" << n << " + (" << b << "x) + (" << c << ")\n";
}

static void showDerivative(double a, double n, double b){
    cout << "Turunan f'(x) = " << (a * n) << "x^" << (n - 1) << " + (" << b << ")\n";
}

static void tableColomnNR(double x){
    cout << setw(20) << right << x << "|";
}

static void tableColomnHeaderNR(string x){
    cout << setw(20) << right << x << "|";
}

static void lineNR(){
    int i = 0; cout << endl;
    while (i < 89){ i++; cout << "-"; }
}

static void tableHeaderNR(){
    cout << "|" << setw(3) << "No.|";
    tableColomnHeaderNR("x");
    tableColomnHeaderNR("f(x)");
    tableColomnHeaderNR("f'(x)");
    tableColomnHeaderNR("x_next");
    lineNR();
}

void runNewtonRaphson() {
    double vA, vN, vB, vC, x0, errorLimit;
    cout << "\nMETODE NEWTON-RAPHSON \n";
    cout << "Masukkan nilai fungsi dengan bentuk f(x) = ax ^ n + bx + c\nNOTE: Jika a tidak diperlukan input 1\n";
    cout << "\nMasukkan a --> "; cin >> vA;
    cout << "Masukkan n --> "; cin >> vN;
    cout << "Masukkan b --> "; cin >> vB;
    cout << "Masukkan c --> "; cin >> vC;  

    showFunctionNR(vA, vN, vB, vC);
    showDerivative(vA, vN, vB);

    cout << "\nMasukkan tebakan awal (x0) --> "; cin >> x0;
    cout << "Masukkan batas error yang ingin dicari --> "; cin >> errorLimit;

    int i = 0;
    double x = x0;
    double fX, dX, x_next, fX_next;

    lineNR(); cout << endl;
    tableHeaderNR();
    //iterasi menggunakan do while untuk mencari akar persamaan
    do {
        i++;
        fX = functionNR(vA, vN, vB, vC, x);
        dX = derivative(vA, vN, vB, x);

        if (dX == 0.0) {
            cout << "\n\n[Error] Nilai turunan f'(x) = 0. Pembagian dengan nol terjadi. Iterasi dihentikan." << endl;
            break;
        }

        x_next = x - (fX / dX);
        fX_next = functionNR(vA, vN, vB, vC, x_next);

        cout << endl << "|" << setw(3) << right << i << "|";
        tableColomnNR(x); tableColomnNR(fX);
        tableColomnNR(dX); tableColomnNR(x_next);

        x = x_next;
    } while (fabs(fX_next) >= errorLimit);
    lineNR();
    
    cout << "\n∵ Jadi, akar dari persamaan ";
    showFunctionNR(vA, vN, vB, vC);
    cout << "Adalah --> " << x << endl;
}