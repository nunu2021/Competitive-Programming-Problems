#include "bits/stdc++.h"

using namespace std;

int main(){

    // convert the integet to binary, and count the number of ones 
    int n, count=0;
    cin >> n;

    while(n){
        count += n & 1;
        n >>=1;
    }
    cout << count << endl;

    return 0;
}