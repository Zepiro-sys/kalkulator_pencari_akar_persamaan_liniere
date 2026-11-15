#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include "metode.h"

using namespace std;

static double inputFunction(int a, int n, int b, int c, double x) {
    return (a * pow(x, n)) + (b * x) + c;
}

void runBiseksi() {
    cin.clear();

    int vA, vN, vB, vC;
    double batasA, batasB, titikTengah, titikSebelumnya, toleransi;
    int iterasi = 0;
    int maxIter = 100;

    cout << "\n METODE BISEKSI" << endl;
    cout << "Bentuk fungsi: f(x) = ax^n + bx + c" << endl;

    cout << "\nMasukkan a, n, b, c (pisahkan dengan spasi): ";
    cin >> vA >> vN >> vB >> vC;

    cout << "Masukkan batas bawah (a): ";
    cin >> batasA;

    cout << "Masukkan batas atas (b) : ";
    cin >> batasB;

    cout << "Masukkan toleransi      : ";
    cin >> toleransi;

    double fA = inputFunction(vA, vN, vB, vC, batasA);
    double fB = inputFunction(vA, vN, vB, vC, batasB);

    if (fA * fB > 0) {
        cout << "\n[Error] Interval [" << batasA << ", " << batasB << "] tidak memiliki perubahan tanda." << endl;
        return;
    }

    cout << "\nPROSES ITERASI" << endl;
    titikSebelumnya = batasA;
    //iterasi menggunakan do while untuk mencari akar persamaan
    do {
        iterasi++;
        titikTengah = (batasA + batasB) / 2.0;

        fA = inputFunction(vA, vN, vB, vC, batasA);
        fB = inputFunction(vA, vN, vB, vC, batasB);
        double fC = inputFunction(vA, vN, vB, vC, titikTengah);

        cout << "\nIterasi " << iterasi << endl;
        cout << "a    = " << batasA << endl;
        cout << "b    = " << batasB << endl;
        cout << "c    = " << titikTengah << endl;
        cout << "f(a) = " << fA << endl;
        cout << "f(b) = " << fB << endl;
        cout << "f(c) = " << fC << endl;

        if (fabs(fC) <= toleransi) break;

        if (fA * fC < 0) {
            batasB = titikTengah;
        } else {
            batasA = titikTengah;
        }

        if (fabs(titikTengah - titikSebelumnya) < 1e-15 || iterasi >= maxIter) break;

        titikSebelumnya = titikTengah;

    } while (fabs(batasB - batasA) > toleransi);

    cout << "\nHASIL AKHIR" << endl;
    cout << "Akar persamaan = " << titikTengah << endl;
    cout << "Jumlah iterasi = " << iterasi << endl;
}