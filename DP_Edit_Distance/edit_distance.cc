#include  "bits/stdc++.h"

using  namespace std;
int dp [1001][1001];
int main(){
    string s,t;
    cin >> s;
    cin >> t;
    if(s.size() == 0){
        cout << t.size() << endl;
        return 0;
    }else if(t.size() == 0){
        cout << s.size() << endl;
        return 0;
    }

    for(int i = 0; i < 1001; i++){
        dp[0][i] = i;
        dp[i][0] = i;
    }

    for(int i = 1; i <= s.size(); i++){
        for (int j = 1; j <= t.size(); j++){
            int cost = 1;
            if(s[i-1] == t[j-1]){
                cost =0 ;
            }
            dp[i][j] = min(dp[i-1][j] +1, dp[i][j-1]+1);
            dp[i][j] = min(dp[i][j], dp[i-1][j-1]+cost);

        }
    }

    cout <<  dp[s.size()][t.size()] << endl;

    return 0;
}