#include "bits/stdc++.h"
using namespace std;
int n, a, b;
int gcd(int a, int b){
    if(b == 0)return a;
    return gcd (b, a%b);
}




int main(){
    cin >> n;
    cin >> a;
    n--;
    
    int count = 0;
    vector <int > fin;
    fin.push_back(a);
    while(n--){
        cin >> b;
        if (gcd(a, b) != 1){
            fin.push_back(1);
            count++;
        }
        fin.push_back(b);
        a = b;
    }

    cout << count << endl;
    for(int i = 0; i < fin.size(); i++){
        cout << fin[i] << " " ;
    }
    cout << endl;
}