#include <iostream>
using namespace std;
int main() {
    int n=0;
    for (int i=1 ; i<=20 ; i++ ) {
        if (i % 2 == 0) {
            n++;
        }
    }
    cout << n << endl;
    return 0;
}