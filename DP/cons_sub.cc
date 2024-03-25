#include "bits/stdc++.h"

using namespace std;
int n, ma, start;
int arr[200001];
map<int, int> hist;
int main(){
    cin >> n;
    int count = 0;
    while(count < n){
        cin >> arr[count];
        count++; 
    }
    ma = 0;
    for(int i = 0; i < n; i++){
        if(hist.find(arr[i]-1)!= hist.end()){
            hist[arr[i]] = max(hist[arr[i]], hist[arr[i]-1]+1);
        }else{
            hist[arr[i]] = 1;
        }

        if(hist[arr[i]] > ma){
            ma = hist[arr[i]];
            start = arr[i] - hist[arr[i]] + 1; // this is the value fo the first number
        }
    }

    cout << ma << endl; 

    int ind = 0;
    int val = start;
    while(val < start + ma){
        if(arr[ind]==val){
            cout << ind+1 <<  " ";
            val++;
        }
        ind++;
    }
    cout << endl;
}   