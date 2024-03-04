#include "bits/stdc++.h"

using namespace std;

typedef long long ull;
ull n, b, x, y, cases;

int main(){
    cin >> cases;
    while(cases--){
        cin >> n >> b >> x >> y;
        ull sum = 0;
        int m = min(b/x, n);
        sum += (m+1)*(0 + m*x)/2;
        int a = m*x;
        while(m < n){
            if(a+x > b){
                a-=y;
            }else{
                a+=x;
            }
            sum += a;
            m++;
        }
        cout << sum << endl;
    }
    return 0;
}


