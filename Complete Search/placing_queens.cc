#include "bits/stdc++.h"

using namespace std;
bitset<30> col, d1, d2;
int nr, nc, n;

void solve(int* count, int r, int local_count){
    if (local_count == n){*count = *count +1; return;}
    if (r == nr)return;
    for(int c = 0; c < nc; c++){
        if (!col[c] && !d1[r-c+(nc-1)] && !d2[r+c]){
            col[c] = d1[r-c+(nc-1)] = d2[r+c] = 1;
            int lc = local_count + 1;
            solve(count, r+1, lc);
            col[c] = d1[r-c+(nc-1)] = d2[r+c] = 0;
        }
    }
    if (r < nr-1) solve(count, r+1, local_count);
}


int main(){
    scanf("%d %d %d",&n, &nr, &nc );
    int ans = 0;
    solve(&ans, 0, 0);
    printf("%d", ans);
    
}

