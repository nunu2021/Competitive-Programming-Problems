#include "bits/stdc++.h"
#define N 100002
using namespace std;
int n;
long long int vals [2][N];
int main(){
    // set up a 2*n array
    // load in all data
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> vals[0][i];
    }
    for(int i = 0; i < n; i++){
        cin >> vals[1][i];
    }

    // set up another 2*n array = 0
    // set the first value of array = the actual height


    // for loop n, loop 2, 
    for(int i = 1; i< n; i++){
        for(int j = 0; j < 2; j++){
            vals[j][i] = max(vals[j][i-1], vals[(j+1)%2][i-1] + vals[j][i]);
        }
    }
    cout << max(vals[0][n-1], vals[1][n-1]) << endl;
    return 0;
}