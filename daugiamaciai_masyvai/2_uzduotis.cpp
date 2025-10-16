#include <iostream>
using namespace std;
int main() {
    int n_miestu = 3 , n_dienu = 7 , n_laiku = 4;
    string laikas[50] = {"rytas" , "diena" , "vakaras" , "naktis"};
    int temperatura[50][50][50] = {
        {{15, 7 , 8, 10} ,{5 , 2 , 3 , 6} , {20 , 23 , 45 , 30} , {17 , 18 , 35 , 16} , {14 , 13 ,35 ,21} , {22 , 20 ,19 ,18} , {5, -5, 0 , 3}},
        {{15, 14 , 35, 10} ,{5 , 2 , 3 , 6} , {20 , 23 , 25 , 30} , {17 , 18 , 15 , 16} , {14 , 13 ,20 ,21} , {22 , 20 ,19 ,18} , {5, -5, 0 , 3}},
        {{15, 7 , 8, 10} ,{5 , 2 , 3 , 6} , {20 , 35 , 25 , 30} , {17 , 18 , 35 , 16} , {27 , 35 ,40 ,50} , {22 , 20 ,19 ,18} , {5, -5, 0 , 3}},
    };
    for(int i=0;i<n_miestu;i++) {
        double sum=0;
        for(int j=0;j<n_dienu;j++) {
            for(int k=0;k<n_laiku;k++) {
                sum+=temperatura[i][j][k];
            }
        }
        cout << i+1 << " miesto vidutine savaites temperatura " << sum/(n_dienu*n_laiku) << endl;
    }
    double dienos_laiko_vidurkis[50] = {};
    double sum_laiku[50] = {};
    int silciausias_index = 0;
    double silciausias = 0;
    for(int i=0;i<n_miestu;i++) {
        for(int j=0;j<n_dienu;j++) {
            for(int k=0;k<n_laiku;k++) {
                sum_laiku[k] += temperatura[i][j][k];
            }
        }
    }
    for(int k=0; k<n_laiku;k++) {
        dienos_laiko_vidurkis[k] = sum_laiku[k]/(n_dienu*n_miestu);
        if (dienos_laiko_vidurkis[k] > silciausias) {
            silciausias = dienos_laiko_vidurkis[k];
            silciausias_index = k;
        }
        cout<< silciausias << endl;
    }
    cout << "silciausias dienos laikas yra: " << laikas[silciausias_index] << " su " << silciausias << " vidutine temperatura" << endl ;


}