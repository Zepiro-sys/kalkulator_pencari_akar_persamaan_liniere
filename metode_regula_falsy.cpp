#include <iostream>
#include <cmath>
#include <iomanip>
#include "metode.h"
using namespace std;

static double function(double a, double n, double b, double c, double x){
    return (a * pow(x, n)) + (b * x) + c;
}  

static void showFunction(double a, double n, double b, double c){
    cout << "\nFungsi f(x) = " << a << "x^" << n << "+(" << b << "x)+(" << c << ")\n";
}

static double countC(double a, double b, double fA, double fB){
    return a - (fA * ((b - a) / (fB - fA)));
}

static double range(double a, double b){
    return a * b;
}

static void tableColomn(double x){
    cout << setw(20) << right << x << "|";
}

static void tableColomnHeader(string x){
    cout << setw(20) << right << x << "|";
}

static void line(){
    int i = 0;
    cout << endl;
    while (i < 131){
        i++;
        cout << "-";
    }
}

static void tableHeader(){
    cout << "|" << setw(3) << "No.|";
    tableColomnHeader("a");
    tableColomnHeader("b");
    tableColomnHeader("fA");
    tableColomnHeader("fB");
    tableColomnHeader("c");
    tableColomnHeader("fC");
    line();
}

void runRegulaFalsi() {
    double a, b, c, fA, fB, fC, vA, vB, vC, vN, errorLimit;
    cout << "\n METODE REGULA FALSI\n";
    cout << "Masukkan nilai fungsi dengan bentuk f(x) = ax ^ n + bx + c\nNOTE: Jika a tidak diperlukan input 1\n";
    cout << "\nMasukkan a --> "; cin >> vA;
    cout << "Masukkan n --> "; cin >> vN;
    cout << "Masukkan b --> "; cin >> vB;
    cout << "Masukkan c --> "; cin >> vC;  

    showFunction(vA, vN, vB, vC);

    while (true) {
        cout << "\nMasukkan batas bawah (a) --> "; cin >> a;
        double tempA = function(vA, vN, vB, vC, a);
        cout << "Masukkan batas atas (b) --> "; cin >> b;
        double tempB = function(vA, vN, vB, vC, b);
        double temp = range(tempA, tempB);

        if (temp < 0) break;
        if (temp > 0) {
            cout << "Range ini tidak ada akar, masukkan batas bawa dan atas yang lain!";
        }
        if (temp == 0) {
            cout << "Salah satu batas berada di titik akar, masukkan batas bawa dan atas yang lain!";
        }
    }
    
    cout << "\nMasukkan batas error yang ingin dicari --> ";
    cin >> errorLimit;

    int i = 0;
    line();
    cout << endl;
    tableHeader();
    //iterasi menggunakan do while untuk mencari akar persamaan
    do {
        i++;
        fA = function(vA, vN, vB, vC, a);
        fB = function(vA, vN, vB, vC, b);
        c = countC(a, b, fA, fB);
        fC = function(vA, vN, vB, vC, c);

        cout << endl << "|" << setw(3) << right << i << "|";
        tableColomn(a); tableColomn(b); tableColomn(fA);
        tableColomn(fB); tableColomn(c); tableColomn(fC);

        if ((fA < 0 && fC < 0) || (fA > 0 && fC > 0)){
            a = c;
        } else {
            b = c;
        }
    } while (fabs(fC) >= errorLimit);
    line();
    
    cout << "\n∵ Jadi, akar dari persamaan persamaan ";
    showFunction(vA, vN, vB, vC);
    cout << "Adalah --> " << c << endl;
}