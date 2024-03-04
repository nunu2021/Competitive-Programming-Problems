#include "../bits/stdc++.h"

using namespace std;
int n, m, temp1, temp2;
int junctions[100002];
vector<int> g[100002];
int num_arr[100002];
int min_arr[100002];
int visited[100002];

void label_g(int curr, int num, int m){

    if(visited[curr] == 1){
        m = min(m, num_arr[curr]);
        min_arr[curr] = m;
        visited[curr] = 2;
    }else if(visited[curr] == 0){
        num_arr[curr] = num;
        min_arr[curr] = num;
        visited[curr] = 1;
        
    }else if( min_arr[curr] > m){
        min_arr[curr] = m;
    }

    for(int i = 0; i < g[curr].size(); i++){
        if(visited[g[curr][i]] == 0){
            num++;
            label_g(g[curr][i], num, num);
        }else if(visited[g[curr][i]] == 1 ){
            label_g(g[curr][i], num, m);
        }else if(m < min_arr[g[curr][i]]){
            label_g(g[curr][i], num, m);
        }
    }
}


int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> junctions[i];
    cin >> m;

    for(int i = 1; i <= m; i++){
        cin >> temp1 >> temp2;
        g[temp1].push_back(temp2);
    }

    int fin_cost = 0;
    int fin_choice = 1;
    int num_scc  =0;
    int numbering = 1;
    for(int j = 1; j <= n; j++){
        if(visited[j]>0)continue;
        label_g(j, j, 1);
        for(int i = 1; i <=n; i++)printf("min: %d, num: %d\n", min_arr[i], num_arr[i]);
        printf("\n");
        map<int, vector<int> > scc;
        int count = 1;
    }

     vector<int> scc_root;
        for(int i = 1; i <= n; i++){
            if(min_arr[i] == num_arr[i] && min_arr[i] != 0){
                scc_root.push_back(i);
            }   
        }
        
        for(int i = 0; i < scc_root.size(); i++){
            vector<int> nodes;
            int ii =scc_root[i];
            vector<int> q;
            q.push_back(ii);
            while(q.size()){

                int curr = q[q.size()-1];
                q.pop_back();
                nodes.push_back(curr);
                for(int y = 0; y < g[curr].size(); y++){
                    if(find(nodes.begin(), nodes.end(), g[curr][y]) == nodes.end()){
                        q.push_back(g[curr][y]);
                    }
                }
            }
            int mm = INT_MAX;
            for(int x = 0; x < nodes.size();x++){
                if(junctions[nodes[x]] < mm){
                    mm = junctions[nodes[x]];
                }
            }
            int mull = 0;
            for(int x = 0; x < nodes.size();x++){
                if(junctions[nodes[x]] == mm){
                    mull++;
                }
            }

            printf("wtf %d %d root: %d\n", mm, mull,scc_root[i]);

            fin_cost +=mm;
            fin_choice *= mull;
        }
    printf("%d %d \n", fin_cost, fin_choice);
    return 0;
}
