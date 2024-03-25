#include "bits/stdc++.h"

using namespace std;
int n, a, c, first_a, first_c;
bool comparePairs(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    if (a.first != b.first) {
        return a.first < b.first; 
    }
    return a.second < b.second; 
}

int main(){
    cin >> n;
    vector< pair< int, int > > d;
    
    for(int i = 1; i < n+1; i++){
        cin >> a >> c;
        if (i == 1){
            first_a = a;
            first_c = c;
        }
        d.push_back(make_pair(a, c));
    }

    sort(d.begin(), d.end(), comparePairs);
    
    int idx = 0;
    for(idx = 0; idx < n; ++idx){
        if(d[idx].first == first_a && d[idx].second == first_c){
            break;
        }
    }

    int cnt = 0;
    int prev_idx = idx;
    for(int i = 1; i < n; i++){
        
        int curr_idx = (i + idx)%n;
        
        
        // printf("%d\n",max(d[prev_idx].second, d[curr_idx].first - d[prev_idx].first));
        cnt += max(d[prev_idx].second, d[curr_idx].first - d[prev_idx].first);
        // printf("order: %d %d %d \n", d[curr_idx].first, d[curr_idx].second, max(d[prev_idx].second, d[curr_idx].first - d[prev_idx].first));
        prev_idx = curr_idx;
    }

    

    cout << cnt << endl;
}

