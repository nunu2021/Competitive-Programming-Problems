#include "bits/stdc++.h"

using namespace std;
map<string, int> visited;
map<string, int> visited_b;
map<string, vector<pair<string, int> > > wg;
string glo;
int glo_num = INT_MAX;

void dfs(int dist, string curr, string aa, string bb){
    visited[curr] = dist;

    for (int i = 0; i< curr.size(); i++){
        if(aa[i] == bb[i]) continue;
        string s (1, curr[i]);
        for( pair<string, int> edge : wg[s]){
            string fin = curr.substr(0, i) + edge.first + curr.substr(i+1, curr.size());
            if(edge.second + dist < visited[fin] || visited[fin] == 0){
                dfs(edge.second + dist, fin, aa, bb);
            }
        }
    }
}

void dfs_b(int dist, string curr, string aa, string bb){
    visited_b[curr] = dist;
    if(visited[curr] && visited[curr] + visited_b[curr] < glo_num){
        glo = curr;
        glo_num = visited[curr] + visited_b[curr];
    }

    for (int i = 0; i< curr.size(); i++){
        if(aa[i] == bb[i]) continue;
        string s (1, curr[i]);
        for( pair<string, int> edge : wg[s]){
            string fin = curr.substr(0, i) + edge.first + curr.substr(i+1, curr.size());
            if(edge.second + dist < visited_b[fin] || visited_b[fin] == 0){
                dfs_b(edge.second + dist, fin, aa, bb);
            }
        }
    }
}

int main(){
    string a, b;
    int n ;
    cin >> a;
    cin >> b;
    cin >> n;

    if(a.size() != b.size()){printf("-1\n"); return 0;}

    int c;
    string aaa, bbb;

    while(n--){
        cin >> aaa >> bbb >>  c;
        pair<string, int> y;
        y.first = bbb;
        y.second = c;
        wg[aaa].push_back(y);
    }

    dfs(1, a, a, b);
    dfs_b(1, b, a, b);

    if(glo_num == INT_MAX){printf("-1\n"); return 0;}

    printf("%d \n%s\n", glo_num-2, glo.c_str());
}