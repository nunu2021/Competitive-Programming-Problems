#include "../bits/stdc++.h"

using namespace std;

int n, m, a, b, l;
vector<int> g [100001];
int visited[100001] = {0};
int tin[100001] = {0};
int tout[100001] = {0};

vector<int> up [100001];

int timer = 0;

void dfs(int curr, int parent){
    visited[curr] = 1;
    tin[curr] = timer;
    timer++;
    up[curr][0] = parent;

    for (int i = 1; i <= l; ++i)
        up[curr].push_back(up[up[curr][i-1]][i-1]);

    for(int n : g[curr]){
        if(!visited[n]){
            dfs(n, curr);
        }
    }
    tout[curr] = timer;
    timer++;
}

int is_anc(int u, int v){
    if(tin[u] < tin[v] && tout[u] > tout[v])return 1;
    return 0;
}

int lca(int u, int v){
    if(is_anc(u, v)){
        return u;
    }
    if(is_anc(v, u)){
        return v;
    }

    
}

int main(){
    cin >> n >> m; 
    for(int i = 0; i< n-1; i++){
        cin >> a >> b; 
        g[a].push_back(b);
        g[b].push_back(a);
    }

    l = log(n);
    if (pow(2, n) < l) l++;


}