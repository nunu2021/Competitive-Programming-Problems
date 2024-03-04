#include "bits/stdc++.h"

using namespace std;
int r1, c1, r2, c2, r, b, k;
int visited [8][8];

int dijkstra_king(int dist, int currx, int curry){
      visited[currx][curry] = dist;
    vector<int> x, y;
    if (currx != 0)x.push_back(currx-1);
    if (currx != 7)x.push_back(currx+1);
    x.push_back(currx);

    if (curry != 0)y.push_back(curry-1);
    if (curry != 7)y.push_back(curry+1);
    y.push_back(curry);

    for(int i = 0; i <x.size(); i++){
        for(int j = 0; j < y.size(); j++){
            if (!(x[i] == currx && y[j] == curry)){
                
                if(visited[x[i]][y[j]] > dist +1){
                    dijkstra_king(dist+1, x[i], y[j]);
                }
            }
        }
    }
}

int dijkstra_rook(int dist, int currx, int curry){
  visited[currx][curry] = dist;
    for(int i = 0; i <8; i++){
        if (!(i == currx && i == curry)){
            if(visited[i][curry] > dist +1){
                dijkstra_rook(dist+1, i, curry);
            }
            if(visited[currx][i] > dist +1){
                dijkstra_rook(dist+1, currx, i);
            }
        }
    }
}

int dijkstra_bishop(int dist, int currx, int curry){
    visited[currx][curry] = dist;
    for(int i = 1; i <8; i++){
        if(currx + i < 8){
            if(curry + i < 8){
                if(visited[currx+i][curry+i] > dist +1){
                    dijkstra_bishop(dist+1, currx+i, curry+i);
                }
            } if(curry - i >=0){
                if(visited[currx+i][curry-i] > dist +1){
                    dijkstra_bishop(dist+1, currx+i, curry-i);
                }
            }
        }
        if(currx - i >= 0){
            if(curry + i < 8){
                if(visited[currx-i][curry+i] > dist +1){
                    dijkstra_bishop(dist+1, currx-i, curry+i);
                }
            } if(curry - i >=0){
                if(visited[currx-i][curry-i] > dist +1){
                    
                    dijkstra_bishop(dist+1, currx-i, curry-i);
                }
            }
        }
    }
}




int main(){

     cin >> r1 >> c1 >> r2 >> c2;

    for(int i = 0; i< 8;i++){
        for (int j = 0; j < 8; j++){
            visited[i][j] = INT_MAX;
        }
    }
   
    dijkstra_king(0, r1-1, c1-1);
    k = visited[r2-1][c2-1];

    for(int i = 0; i< 8;i++){
        for (int j = 0; j < 8; j++){
            visited[i][j] = INT_MAX;
        }
    }

    dijkstra_rook(0, r1-1, c1-1);
    r = visited[r2-1][c2-1];

     for(int i = 0; i< 8;i++){
        for (int j = 0; j < 8; j++){
            visited[i][j] = INT_MAX;
        }
    }

    
    dijkstra_bishop(0, r1-1, c1-1);
    b = visited[r2-1][c2-1];

    if(r == INT_MAX)r = 0;
    if(b == INT_MAX)b = 0;
    if(k == INT_MAX)k = 0;

    printf("%d %d %d\n", r, b, k);
    

}