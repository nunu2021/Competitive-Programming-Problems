#include "bits/stdc++.h"

using namespace std;

// bool bfs(map<int, vector<int> >  g, int start, int end){
//     int e = 0;
//     vector<int> q;
//     q.push_back(start);

//     map<int, vector<int> > visited;
//     while(q.size()!= 0){

//         int curr = q.front();
//         q.erase(q.begin());

//         for(int i = 0; i< g[curr].size();i++){
            
//             if (g[curr][i] == end){
//                 return true;
//             }
//             if(find(visited[curr].begin(), visited[curr].end(), g[curr][i]) == visited[curr].end()){
//                 q.push_back(g[curr][i]);
//                 visited[curr].push_back(g[curr][i]);
//             }
           
//         }
//     }
//     return false;
// }

int main(){
    int n, s;
    cin >> n >>s;
    int count = 0;
    map<int, vector<int> > g;
    vector<int> in;
    vector <int> out;

    while(count < n){
        int b;
        cin >> b;
        in.push_back(b);
        count++;
    }
    
    while(count >0){
        int b;
        cin >> b;
        out.push_back(b);
        count--;
    }



    if(!in[0]  || (!out[s-1] && !in[s-1])){printf("NO\n");return 0;}

    if(in[s-1]== 1){
        printf("YES\n");
        return 0;
    }

    bool over = false;
    for ( int i = s-1; i < n ; i++){
        if (in[i] && out[i]){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");return 0;
}