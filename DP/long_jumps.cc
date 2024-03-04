#include "bits/stdc++.h"

using namespace std;
int n, a;
int vals[200008], dp[200009]; // make an a+1 dp array

int main(){
    cin >> n;

    while(n--){
        memset(vals, 0, 200008);
        cin >> a;
        for(int i = 0; i < a; i++){
            cin >> vals[i];
        }

        memset(dp, 0, 200009); // set everything to 0

// for loop from 0 to a-1
//      dp[i+vals[i]] = max(dp[i+vals[i]], dp[i] + vals[i])
        for(int i =0; i < a; i++){
            int next = min(a, i + vals[i]);
            dp[next] = max(dp[next], dp[i] + vals[i]);
        } 
        cout << dp[a] << endl;       
    }
}

// [7 3 1 2 3]




