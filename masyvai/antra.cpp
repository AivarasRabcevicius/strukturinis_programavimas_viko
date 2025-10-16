#include <iostream>
using namespace std;
int a[40] = {9 , 2, 5 ,4, 4, 2, 2, 1, 1, 5, 5, 8, 6, 4, 1, 7 ,1, 2, 10, 10 ,10 , 9 , 2, 3, 5, 2, 4, 7, 5, 6, 7, 4, 5, 7, 3, 9, 5, 3, 9 , 5};
int taskai[10] = {0};
int main() {

    for (int i = 0; i < 40; i++) {
        taskai [a[i]]++;
    }
    for (int i = 1; i <= 10; i++) {
        cout << "zaidimas ivertintas " << i << " taskais " << taskai[i] << " kartus" << endl;
    }
}
