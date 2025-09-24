#include <iostream>
using namespace std;
int main() {
    int e;
    cin >> e;
    if (e == 10) {
        cout <<" puiku" << endl;
    }
    else if (e == 9 ){
        cout << " labai gerai" << endl;
    }
    else if (e == 7 or e==8) {
        cout <<" gerai" << endl;
    }
    else if (e == 5 or e==6) {
        cout <<" patenkinamas" << endl;
    }
    else {
        cout <<" egzaminas neislaikytas" << endl;
    }
    return 0;
}