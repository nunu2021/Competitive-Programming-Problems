#include "bits/stdc++.h"

using namespace std;

map<int, vector<int> > g;
int visited [100001] = {0};
int ds[2] = {0};


void dfs(int color, int curr){
    ds[color]+=1;
    visited[curr] = 1;
    for(int nbr: g[curr]){
        if(!visited[nbr]){
            dfs((color+1)%2, nbr);

        }
    }
}

int main(){
    int n;
    cin >> n;
    int u, v;
    int nn = n;

    n--;
    while(n--){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, 1);
    long long int m1 = ds[0];
    long long int m2 = ds[1];
    long long int nnn = (nn-1);
    printf("%lld\n",((m1*m2) - (nnn)));
}

