#include "bits/stdc++.h"
#define N 1010101
#define sff(n,m) scanf("%d%d",&n,&m)
#define pfs(s) printf("%s",s)
#define pb push_back
#define pf(n) printf("%d",n)
using namespace std;


int sz;
bool vis[N];
vector<int> adj[N];

void dfs(int s)
{
    vis[s] = true;
    sz++;

    for(int e : adj[s])
    {
        if(!vis[e])
            dfs(e);
    }
}

int main()
{

    int i, j, k;
    int n, m;
    int u, v;

    sff(n, m);
    for(i = 0; i < m; i++)
    {
        sff(u, v);

        adj[u].pb(v);
        adj[v].pb(u);
    }

    int cnt = 0;
    for(i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            sz = 0;
            dfs(i);

            cnt += (sz - 1);
        }
    }

    pf(m - cnt);

    return 0;
}