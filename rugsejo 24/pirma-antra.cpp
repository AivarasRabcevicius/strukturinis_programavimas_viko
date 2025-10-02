#include <iostream>
using namespace std;
int main() {
    double vidurkis , a=3 , b=6 , c=5 , d=3;

    vidurkis = (a+b+c+d)/4;
    if (vidurkis >= 5) {
        cout << vidurkis << " vidurkis teigiamas" << endl;
    }
    else {
        cout << vidurkis << " vidurkis neigiamas" << endl;
    }
    return 0;
}