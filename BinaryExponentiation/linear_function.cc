#include "bits/stdc++.h"

using namespace std;
long long int a, b, n , x;
long long int mod = 1000000007;




int main(){
    cin >> a >> b >> n >> x;
    long long int power = 1;
    long long int fin = 0;



    while(n){
        fin += (b * power);
        fin %= mod;
        power *= a;
        power %= mod;
        n--;
    }
    fin += (x * power);
    fin %= mod;

    cout << fin << endl;
    return 0;

}