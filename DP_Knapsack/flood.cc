#include "../bits/stdc++.h"
using namespace std;


int dp[101][2001], t[101], d[101], p[101], n;
map <int, vector<int> > c;
vector<pair<int, int> > dd;

bool sortByFirst(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}

int main(){
    cin >> n;
    int max_d = 0;
    int tt, ddd, pp;
    for(int i = 1 ; i <= n; i++){
        scanf("%d %d %d", &tt, &ddd, &pp);
        max_d = max(max_d, ddd);
        t[i] = tt; d[i] = ddd; p[i] =pp;
        dd.push_back(make_pair(ddd, i));
        c[pp].push_back(i);
    }

    for(int i = 0; i < 101;i++){
        memset(dp[i], 0, sizeof(int)* 2001);
    }

    

    // sort indexes based on comparing values in v
    sort(dd.begin(), dd.end(), sortByFirst);

    for(int i = 0; i< n; i++){
        printf("%d, ", dd[i].first);
    }

    cout << endl;


    for(int ii = 1; ii <= n; ii++){
    for(int j = 1; j <= max_d; j++){
            int i = dd[ii].second;

            // if not too late
            // max of not saving the item, and saving the item
            int temp;
            if(d[i] > j && d[i] > t[i] && j >= t[i]){
                dp[ii][j] = max(dp[ii][j], dp[ii-1][j-t[i]] + p[i]);
            }
            dp[ii][j] = max(dp[ii][j], dp[ii][j-1]);
            dp[ii][j] = max(dp[ii][j], dp[ii-1][j]);
    

        }
    }
    printf("%d\n", dp[n][max_d]);
    int count = 0;
    int prev = 0;
    vector <int> l;
    for(int i  =0; i <= max_d; i++){
        if(dp[n][i] > prev && c.find(dp[n][i]-prev)!= c.end()){ // new item detected
            count++;
            int value = c[dp[n][i]-prev][c[dp[n][i]-prev].size() -1];
            c[dp[n][i]-prev].pop_back();
            l.push_back(value);
            prev = dp[n][i];
        }
    }
    cout << count << endl;
    for(int i = 0;i< l.size(); i++){
        cout << l[i] << ' ';
    }
    cout << endl;
    return 0;

}