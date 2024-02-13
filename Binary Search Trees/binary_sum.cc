#include "bits/stdc++.h"

using namespace std;
int n;

int main(){
    cin >> n;
    while (n--){
        long long int c = 0; long long int sum = 0;
        cin >> c;
        while(c){
            sum+=c;
            c = c/2;
        }
        cout << sum << endl;
    }
}