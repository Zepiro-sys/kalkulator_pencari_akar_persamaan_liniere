#include <iostream>
#include <limits>
#include "metode.h"

using namespace std;

int main() {
    int pilihan;

    do {
        cout << "   PROGRAM UTAMA PENCARIAN AKAR FUNGSI   \n";
        cout << "1. Metode Biseksi\n";
        cout << "2. Metode Regula Falsi\n";
        cout << "3. Metode Newton-Raphson\n";
        cout << "4. Metode Secant\n";
        cout << "5. Keluar\n";
        cout << "-----------------------------------------\n";
        cout << "Pilih metode (1-5) --> ";

        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInput tidak valid! Masukkan angka 1-5.\n";
            continue;
        }

        switch (pilihan) {
            case 1:
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                runBiseksi();
                break;
            case 2:
                runRegulaFalsi();
                break;
            case 3:
                runNewtonRaphson();
                break;
            case 4:
                runSecant();
                break;
            case 5:
                cout << "\nTerima kasih! Program selesai.\n";
                break;
            default:
                cout << "\nPilihan tidak valid. Silakan masukkan angka 1-5.\n";   
        }
    } while (pilihan != 5);

    return 0;
}

//untuk menjalankan program
// ketik di terminal: g++ *.cpp -o program_utama.exe
//setelah itu jalankan program dengan mengetik: ./program_utama.exe