#include "bits/stdc++.h"

using namespace std;
long long int t, mod, a, b;
int main(){
    cin >> t >> mod;

    while(t--){
        cin >> a >> b;
        long long int curr = 1;
        long long int a_pw = a;
        while(b){
            long long int power = b&1;
            long long int powerr = pow((a_pw % mod), power);
            curr *= powerr%mod;
            curr %= mod;
            a_pw *= a_pw;
            a_pw %= mod;
            b >>= 1;
        }
        long bruh = curr % mod;
        cout << bruh << endl;

    }
    return 0;
}