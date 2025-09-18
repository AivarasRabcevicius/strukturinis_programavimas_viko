#include <iostream>
using namespace std;
int main() {
    int sk;
    cin >> sk;
    int desimtainis = sk /10;
    int vienetainis = sk % 10;
    cout << desimtainis+vienetainis;
    return 0;
}