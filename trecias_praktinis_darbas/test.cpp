#include <iostream>
using namespace std;
int main() {
    int a=100;
    int& b=a;
    b= a*a;
    a = b/b;
    cout<< a << " " << b <<endl;
}