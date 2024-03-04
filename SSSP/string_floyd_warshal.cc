#include "../bits/stdc++.h"

using namespace std;

int N = 26;
char g [26][26];

int main(){
    for(int i = 0 ; i < N; i++){
        for (int j = 0; j < N; j++){
            if (i == j){
                g[i][j] = 0;
            }else{
                g[i][j] = INT_MAX;
            }
            
        }
    }

    string a, b;
    cin >> a >> b;

    if(a.size() != b.size()){cout << -1; return 0;}

    int n, c;
    cin >> n;
    char x, y;

    while(n--){
        cin >> x >> y >> c;
        g[x - 'a'][y-'a'] = c;
    }

    // floyd warshall
    for(int i  = 0; i < N; i++){
        for(int j  = 0; j < N; j++){
            for (int k = 0; k < N; k++){
                if(g[i][k] + g[k][j] < g[i][j]){
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }

    int count = 0;
    string s;
    for(int i = 0; i < a.size(); i++){
        int dis = INT_MAX;
        char h;
        for(int j = 0; j< N; j++){
            printf("%d %d\n", g[a[i]-'a'][j], g[j][b[i]-'a']);
            if(g[a[i]-'a'][j] != INT_MAX && g[j][b[i]-'a']!= INT_MAX ){
                
                if(g[a[i]-'a'][j] + g[j][b[i]-'a'] < dis){
                    dis = g[a[i]-'a'][j] + g[j][b[i]-'a'];
                    h = 'a'+j;
                }
            }
        }
        cout << endl;

        if(dis == INT_MAX){
            cout << -1;
            return 0;
        }

        count += dis;
        s += string(1, h);
    }

    cout << count << endl;
    cout << s;
    return 0;


}