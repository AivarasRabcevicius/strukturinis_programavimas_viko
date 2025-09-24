#include <iostream>
using namespace std;
int main() {
    double pinigai = 1000;
    for (int i=0 ; i<10 ; i++ ) {
        pinigai = pinigai * 1.05;
        }
    cout << pinigai << endl;
    return 0;
}