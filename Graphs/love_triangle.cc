#include "bits/stdc++.h"

using namespace std;

int main(){
    int n;
    cin >> n;

    map<int, vector<int> > like;

    int count =1;
    while(count <= n){
        int f;
        cin >> f;
        like[count].push_back(f);

        for(vector<int>::iterator p = like[count].begin(); p!= like[count].end(); p++){
            int pp = *p;
            for(vector<int>::iterator y = like[pp].begin(); y!= like[pp].end(); y++){
                int yy = *y;
                for(vector<int>::iterator x = like[yy].begin(); x!= like[yy].end(); x++){
                    if (*x == count){
                        printf("YES\n");
                        return 0;
                    }
                }
            }
        }
        count++;
    }
    printf("NO\n");
    return 0;
}