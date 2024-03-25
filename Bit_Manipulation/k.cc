#include "bits/stdc++.h"

using namespace std;
int n, val;
int main(){
    cin >> n;
    while(n--){
        cin >> val;
        int inc = val;
        while(val != 0){
            inc--;
            val &= inc;
            
        }
        cout << inc << endl;
    }
}