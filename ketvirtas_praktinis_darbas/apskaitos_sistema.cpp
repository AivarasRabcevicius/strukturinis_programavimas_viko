#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct menuItemType {
    string menuItem; // patiekalo pavadinimas
    double menuPrice; // patiekalo kaina (2 skaitmenys po kablelio)
} menu[50];

int uzsakymas[50], kiekis[50];
double suma = 0;

int i = 0, u = 0;
char choice;
bool quit = false;

void printCheck() {
    quit = true;
    ofstream myfile;
    myfile.open("receipt.txt");
    for (int j = 0; j < u; j++) {
        myfile << menu[uzsakymas[j]].menuItem << "  x" << kiekis[j] << " " << menu[uzsakymas[j]].menuPrice << endl;
        cout << menu[uzsakymas[j]].menuItem << "  x" << kiekis[j] << " " << menu[uzsakymas[j]].menuPrice << endl;
        suma = suma + menu[uzsakymas[j]].menuPrice * kiekis[j];
    }
    myfile << "Viso be PVM:" << suma << endl;
    cout << "Viso be PVM:" << suma << endl;
    myfile << "VIso " << fixed << setprecision(2) << suma * 1.21 << endl;
    cout << "VIso " << fixed << setprecision(2) << suma * 1.21 << endl;
    myfile.close();
}

void getData() {
    cout << "skaitomas failas..." << endl;
    fstream myfile;
    myfile.open("menu.txt");
    if (myfile.is_open()) {
        cout << "failas atidarytas" << endl;
    }
    while (!myfile.eof()) {
        myfile >> menu[i].menuItem;
        myfile >> menu[i].menuPrice;
        // cout << menu[i].menuItem;
        // cout << menu[i].menuPrice;
        i++;
    }
    myfile.close();
}

void showMenu() {
    while (quit == false) {
        cout << "jūsų krepšelyje:" << endl;
        if (u == 0) cout << "TUŠČIA" << endl;
        for (int j = 0; j < u; j++) {
            cout << menu[uzsakymas[j]].menuItem << "  x" << kiekis[j] << " " << menu[uzsakymas[j]].menuPrice << endl;
        }
        cout << "Šiandienos meniu:" << endl;
        cout << "Iveskite meniu numeri noredami pridėti prie užsakymo" << endl;
        cout << "Kai pridėjote viską ko norit, iveskite U" << endl;
        for (int j = 0; j < i; j++) {
            cout << j + 1 << ". " << menu[j].menuItem << "    " << menu[j].menuPrice << endl;
        }
        cout << "u. Užsakyti" << endl;
        cin >> choice;
        if (isdigit(choice)) {
            uzsakymas[u] = int(choice) - 49;
            cout << "pasirinkite porciju kieki:" << endl;
            cin >> kiekis[u];
            // cout << "TESTTST" << uzsakymas[u];
            u++;
        } else if (choice == 'u') printCheck();
    }
}


int main() {
    getData();
    showMenu();
}
