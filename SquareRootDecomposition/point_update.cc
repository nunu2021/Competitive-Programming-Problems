#include "bits/stdc++.h"

using namespace std;

int n, m, a, b, c;
int main(){
    cin >> n >> m;

    int arr [n];
    for(int i = 0; i < n; i++)arr[i] = 0;

    while(m--){
        // for each operation:
        cin >> a >> b >> c;

        if(a == 1){ // just adding

            for(int i = b-1; i < n; i++){
                arr[i]+=c;
            }
        }else{ // do the summation and print
            if (b == 1){
                cout << arr[c-1] << endl;
            }else{
                // cout << " hoyaaaa " << arr[c-1] << arr[b-2] <<endl;
                cout << arr[c-1] - arr[b-2] << endl;
            }
            
        }

    }
    return 0;
}
