#include <iostream>
using namespace std;
int choice_main, choice_2, pazymiai[100][10] = {}, n_mokiniu, n_pazymiu;
int mokinio_numeris, pazymio_numeris, naujas_pazymis;
int issaugota_mokiniu = 0;
string vardai[100] = {};
bool break_cmd = false;

int main() {
    while (true) {
        cout << "pasirinkite veiksma:" << endl;
        cout << "1. Įvesti mokinių vardus ir jų pažymius" << endl;
        cout << "2. Peržiūrėti visų mokinių arba konkretaus mokinio pažymius." << endl;
        cout << "3. Atnaujinti konkretų pažymį konkrečiam mokiniui." << endl;
        cout << "4. Pašalinti mokinį iš sąrašo." << endl;
        cout << "5. Uzdaryti" << endl;
        cin >> choice_main;
        switch (choice_main) {
            case 1: {
                cout << "kiek mokiniu ivesti?(iki 100)" << endl;
                cin >> n_mokiniu;
                cout << "kiek pazymiu per mokini?(iki 10)" << endl;
                cin >> n_pazymiu;
                for (int i = issaugota_mokiniu; i < issaugota_mokiniu + n_mokiniu; i++) {
                    cout << "iveskite " << i + 1 << " mokinio varda:" << endl;
                    cin >> vardai[i];
                    for (int j = 0; j < n_pazymiu; j++) {
                        cout << "iveskite " << i + 1 << " mokinio " << j + 1 << " pazymi:" << endl;
                        cin >> pazymiai[i][j];
                    }
                }
                issaugota_mokiniu += n_mokiniu;
                break;
            }
            case 2: {
                cout << "pasirinkite veiksma:" << endl;
                cout << "1. perziureti visu mokiniu pazymius" << endl;
                cout << "2. perziureti konkretaus mokinio pazymius" << endl;
                cin >> choice_2;
                switch (choice_2) {
                    case 1: {
                        for (int i = 0; i < issaugota_mokiniu; i++) {
                            cout << vardai[i] << "  ";
                            for (int j = 0; j < n_pazymiu; j++) {
                                cout << pazymiai[i][j] << " ";
                            }
                            cout << endl;
                        }
                        break;
                    }
                    case 2: {
                        cout << "iveskite mokinio numeri:" << endl;
                        cin >> mokinio_numeris;
                        mokinio_numeris -= 1;
                        cout << vardai[mokinio_numeris] << " ";
                        for (int j = 0; j < n_pazymiu; j++) {
                            cout << pazymiai[mokinio_numeris][j] << " ";
                        }
                        cout << endl;
                    }
                    break;
                }
                break;
            }
            case 3: {
                cout << "iveskite mokinio numeri:" << endl;
                cin >> mokinio_numeris;
                mokinio_numeris -= 1;
                cout << "iveskite pazymio numeri:" << endl;
                cin >> pazymio_numeris;
                pazymio_numeris -= 1;
                cout << "mokinio " << vardai[mokinio_numeris] << " senas pazymis: " << pazymiai[mokinio_numeris][
                    pazymio_numeris] << ", iveskite nauja:" << endl;
                cin >> naujas_pazymis;
                pazymiai[mokinio_numeris][pazymio_numeris] = naujas_pazymis;
                break;
            }
            case 4: {
                cout << "pasirinkite pasalinamo mokinio numeri:" << endl;
                cin >> mokinio_numeris;
                mokinio_numeris -= 1;
                for (int i = mokinio_numeris; i < issaugota_mokiniu; i++) {
                    vardai[i] = vardai[i+1];
                    for (int j = 0; j < n_pazymiu; j++) {
                        pazymiai[i][j] = pazymiai[i+1][j];
                    }
                }
                issaugota_mokiniu -= 1;
                break;
            }
            case 5: {
                break_cmd = true;
                break;;
            }
        }
        if (break_cmd) {
            break;
        }
    }
}
