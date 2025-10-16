#include <iostream>
using namespace std;
int sum=0 , minimum, maximum;
int main() {
  int a[5] = {};
  for (int i = 0; i < 5; i++) {
    cout << "iveskite " << i+1 << " skaiciu" << endl;
    cin >> a[i];
  }
  minimum = a[0];
  maximum = a[0];
  for (int i = 0; i < 5; i++) {
     sum = sum + a[i];
      if (a[i] < minimum) minimum = a[i];
      if (a[i] > maximum) maximum = a[i];
  }
  cout << "didziausias: " << maximum << ", maziausias: " << minimum << ", suma: " << sum <<endl;
}