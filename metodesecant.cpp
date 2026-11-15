#include <iostream>
#include <cmath>
#include <iomanip>
#include "metode.h"
using namespace std;

static double functionSecant(double a, double n, double b, double c, double x){
    return (a * pow(x, n)) + (b * x) + c;
}  

static void showFunctionSecant(double a, double n, double b, double c){
    cout << "\nFungsi f(x) = " << a << "x^" << n << " + (" << b << "x) + (" << c << ")\n";
}

static void tableColomnSecant(double x){
    cout << setw(16) << right << x << "|";
}

static void tableColomnHeaderSecant(string x){
    cout << setw(16) << right << x << "|";
}

static void lineSecant(){
    int i = 0; cout << endl;
    while (i < 108){ i++; cout << "-"; }
}

static void tableHeaderSecant(){
    cout << "|" << setw(3) << "No.|";
    tableColomnHeaderSecant("x_i-1");
    tableColomnHeaderSecant("x_i");
    tableColomnHeaderSecant("x_next");
    tableColomnHeaderSecant("f(x_i-1)");
    tableColomnHeaderSecant("f(x_i)");
    tableColomnHeaderSecant("f(x_next)");
    lineSecant();
}

void runSecant() {
    double vA, vN, vB, vC, x0, x1, errorLimit;
    cout << "\n METODE SECANT \n";
    cout << "Masukkan nilai fungsi dengan bentuk f(x) = ax^n + bx + c\nNOTE: Jika a tidak diperlukan input 1\n";
    cout << "\nMasukkan a --> "; cin >> vA;
    cout << "Masukkan n --> "; cin >> vN;
    cout << "Masukkan b --> "; cin >> vB;
    cout << "Masukkan c --> "; cin >> vC;  

    showFunctionSecant(vA, vN, vB, vC);

    cout << "\nMasukkan tebakan awal ke-1 (x0) --> "; cin >> x0;
    cout << "Masukkan tebakan awal ke-2 (x1) --> "; cin >> x1;
    cout << "Masukkan batas error (toleransi)--> "; cin >> errorLimit;

    int i = 0;
    double f0, f1, x2, f2;

    lineSecant(); cout << endl;
    tableHeaderSecant();
    
    do {
        i++;
        f0 = functionSecant(vA, vN, vB, vC, x0);
        f1 = functionSecant(vA, vN, vB, vC, x1);

        // Pencegahan pembagian dengan nol
        if (f1 - f0 == 0.0) {
            cout << "\n\n[Error] f(x_i) - f(x_i-1) = 0. Pembagian dengan nol terjadi. Iterasi dihentikan." << endl;
            break;
        }

        // Rumus iterasi Secant
        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);
        f2 = functionSecant(vA, vN, vB, vC, x2);

        cout << endl << "|" << setw(3) << right << i << "|";
        tableColomnSecant(x0); 
        tableColomnSecant(x1); 
        tableColomnSecant(x2); 
        tableColomnSecant(f0); 
        tableColomnSecant(f1);
        tableColomnSecant(f2);

        // Update nilai untuk iterasi selanjutnya
        x0 = x1;
        x1 = x2;
        
    } while (fabs(f2) >= errorLimit && i < 100); // Batas aman 100 iterasi agar tidak infinite loop
    lineSecant();
    
    cout << "\n∵ Jadi, estimasi akar dari persamaan ";
    showFunctionSecant(vA, vN, vB, vC);
    cout << "Adalah --> " << x2 << endl;
}