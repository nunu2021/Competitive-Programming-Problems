#include "bits/stdc++.h"

using namespace std;

int main(){
    int v, e;
    cin >> v >> e;

    int e2 = e;
    map<int,vector<int> > ad_list;
    while(e--){
        int a, b;
        cin >> a >> b;
        ad_list[a].push_back(b);
        ad_list[b].push_back(a);
        if ((ad_list[a].size() == v-1 || ad_list[b].size() == v-1) && e2 == v-1){
            printf("star topology\n"); return 0;
        }
    }

    bool single = false;

    for(int i = 1; i<= v; i++){
        if (ad_list[i].size() == 1){
            single = 1;
        }
        else if(ad_list[i].size()!= 2 ){
            printf("unknown topology\n"); return 0;
        }
    }
    if (single){
       printf("bus topology\n"); return 0;
    }
    printf("ring topology\n"); return 0;

}
