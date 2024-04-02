#include "bits/stdc++.h"

using namespace std;
long long int tt, mod, b, a;

vector<vector<long long int> > multiply_matrix(vector<vector<long long int> > a, vector<vector<long long int> > b){
    vector<vector<long long int> > ret;
    vector<long long int> ret1;
    vector<long long int> ret2;

    ret1.push_back((a[0][0]*b[0][0] + a[0][1]*b[1][0])%mod);
    ret1.push_back((a[0][0]*b[0][1] + a[0][1]*b[1][1])%mod);

    ret2.push_back((a[1][0]*b[0][0] + a[1][1]*b[1][0])%mod);
    ret2.push_back((a[1][0]*b[0][1] + a[1][1]*b[1][1])%mod);

    ret.push_back(ret1);
    ret.push_back(ret2);
    return ret;
}


int main(){
    cin >> tt >> mod;

    while(tt--){
        cin >>  b;


        if (b <2){
            cout << 1 << endl;
            continue;
        }
        b--;

        long long int a_pw = a;

        vector<vector<long long int> > a;
        vector<long long int> t;
        t.push_back(1);
        t.push_back(1);
        a.push_back(t);
        vector<long long int> t1;
        t1.push_back(1);
        t1.push_back(0);
        a.push_back(t1);

        vector<vector<long long int> > curr;
        vector<long long int> c;
        c.push_back(1);
        c.push_back(0);
        curr.push_back(c);
        vector<long long int> c1;
        c1.push_back(0);
        c1.push_back(1);
        curr.push_back(c1);


        while(b){
            long long int power = b&1;
            if (power > 0){
                curr = multiply_matrix(a, curr);
            }
        
            a = multiply_matrix(a, a);
            b >>= 1;
        }

        cout << (curr[0][0] + curr[0][1]) % mod << endl;

    }
    return 0;
}