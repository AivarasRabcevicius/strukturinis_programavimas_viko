#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
bool quit=false;
int choice_main;
double bilietu_skaicius, bilieto_kaina, esamas_atlyginimas[10], padidejes_atlyginimas[10], padidejimas[10], total = 0,
        total_bilietu = 0;
string pavarde[10], vardas[10];

int ataskaita() {
    cout << "skaitomas failas..." << endl;
    fstream myfile;
    myfile.open("futbolas.txt");
    if (myfile.is_open()) {
        cout << "sekmingai nuskaityta" << endl;
    }
    while (!myfile.eof()) {
        myfile >> bilieto_kaina;
        myfile >> bilietu_skaicius;
        cout << bilieto_kaina << endl;
        cout << bilietu_skaicius << endl;
        total = total + bilieto_kaina * bilietu_skaicius;
        total_bilietu += bilietu_skaicius;
    }
    myfile.close();
    cout << setprecision(2) << fixed << "is viso uzdirbta: " << total << endl;
    cout << setprecision(2) << fixed << "is viso parduota: " << total_bilietu << endl;
    ofstream failas("stadiono ataskaita.txt");
    failas << setprecision(2) << fixed << "is viso uzdirbta: " << total << endl;
    failas << "is viso parduota: " << total_bilietu << endl;
    failas.close();
    return 0;
}

int atlyginimai() {
    fstream myfile;
    myfile.open("salary.txt");
    if (myfile.is_open()) {
        cout << "sekmingai nuskaityta" << endl;
    }
    int i = 0;
    while (!myfile.eof()) {
        myfile >> pavarde[i];
        myfile >> vardas[i];
        myfile >> esamas_atlyginimas[i];
        myfile >> padidejimas[i];
        i++;
    }
    myfile.close();
    ofstream failas("newSalary.txt");
    for (int j = 0; j < i; j++) {
        failas << pavarde[j] << " " << vardas[j] << " " << setprecision(2) << fixed << esamas_atlyginimas[j] * (
            1 + padidejimas[j] / 100) << endl;
    }
    failas.close();
    return 0;
}


int main() {
    while (quit == false) {
    cout << "pasirinkite programa:" << endl;
    cout << "1. Futbolo stadiono ataskaita" << endl;
    cout << "2. Atlygio skaiciuokle" << endl;
    cout << "3. iseiti" << endl;
    cin >> choice_main;
        switch (choice_main) {
            case 1: {
                ataskaita();
                break;
            }
            case 2: {
                atlyginimai();
                break;
            }
            case 3: {
                quit = true;
            }
        }
    }
}
