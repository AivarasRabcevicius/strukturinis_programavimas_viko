#include <iostream>
#include <array>
using namespace std;
array<int, 5> arr = {{}};
int disc(int matrix[5][5], int n) {
    int a[n][n-1][n-1];
    for (int i=0 ; i<n ; i++) {
        for (int ai = 1 ; ai<n-1 ; ai++) {
            for (int aj = 1 ; aj<n-1 ; aj++) {
                a[i][ai-1][aj-1] = matrix[ai][aj];
            }
        }
    }
    array<int, 5> res = n;
    return 0;
}

int main() {
    int n=5;
    int m[5][5] =  {
        {4, 0, 3, 2, 2} ,
        {4, 0, 3, 2, 2} ,
        {4, 0, 3, 2, 2} ,
        {4, 0, 3, 2, 2} ,
        {4, 0, 3, 2, 2}
    };
    int adj = disc(m, n);

    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<n ; j++) {
            cout << adj[i][j];
        }
    }
return 0;
}