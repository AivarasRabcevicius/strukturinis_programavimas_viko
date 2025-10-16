#include <iostream>
using namespace std;
int main() {
    int n_studentu , n_dalyku;
    cout<< "iveskite studentu skaiciu";
    cin>> n_studentu;
    cout<< "iveskite dalyku skaiciu";
    cin >> n_dalyku;
    int lentele[50][50] = {};
    for (int i = 0; i < n_studentu; i++) {
        for (int j = 0 ; j < n_dalyku ; j++) {
            cout<< "iveskite " << i+1 << " studento " << j+1 << " dalyko pazymi";
            cin >> lentele[i][j];
        }
    }
    double vidurkiai[50] = {};
    for (int i = 0; i < n_studentu; i++) {
        double sum = 0;
        for (int j = 0 ; j < n_dalyku ; j++) {
            sum += lentele[i][j];
        }
        vidurkiai[i] = sum/n_dalyku;
        cout<< i+1 <<" sudento vidurkis: " <<  vidurkiai[i]<< endl;
    }
    double dalyko_vidurkiai[50] = {};
    for (int j = 0; j < n_dalyku; j++) {
        double sum = 0;
        for (int i = 0 ; i< n_studentu ; i++) {
            sum += lentele[i][j];
        }
        dalyko_vidurkiai[j] = sum/n_studentu;
        cout<< j+1 << " dalyko vidurkis: " <<  dalyko_vidurkiai[j]<< endl;
    }

    double bendras_vidurkis;
    double sum = 0;
    for (int i = 0; i < n_studentu; i++) {
        for (int j = 0 ; j < n_dalyku ; j++) {
            sum += lentele[i][j];
        }
    }
    bendras_vidurkis = sum/(n_dalyku*n_studentu);
    cout<<"bendras vidurkis: " <<  bendras_vidurkis<< endl;
}