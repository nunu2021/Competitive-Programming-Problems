#include "../bits/stdc++.h"

using namespace std;
uint64_t g[500][500];
uint64_t n, r;

uint64_t run_floyd_warshall(){
    uint64_t dist[n][n];
    for(int i = 0; i< n; i++){
        for(int j = 0; j < n; j++){
            dist[i][j] = g[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for (int j =0; j < n; j++){
            for (int k = 0; k < n; k++){
                if(dist[i][k] != 4294967295 && dist[k][j]!= 4294967295 ){
                    dist[i][j] = min(dist[i][j], (dist[i][k] + dist[k][j]));
                }
            }
        }
    }

    uint64_t sum =0;
    for(int i = 0; i< n; i++){
        for(int j = 0; j < n; j++){
            if(dist[i][j] != 4294967295){
                sum+=dist[i][j];
            }
        }
    }
    return sum;

}


int main(){

    cin >> n;
    int count = 0;

    while(count < n){
        for(int i = 0; i< n; i++){
            cin >> g[count][i];
        }
        count++;
    }

    for(int i = 0; i< n; i++){
        cin >> r;
        cout << run_floyd_warshall() << " ";
        for(int j = 0; j< n; j++){
            g[r-1][j]= 4294967295;
            g[j][r-1] = 4294967295;
        }
    }

    return 0;
}