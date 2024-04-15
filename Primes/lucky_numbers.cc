#include "bits/stdc++.h"

using namespace std;

int main(){
    int sf[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 744, 774, 477, 747, 777};

    bool t = false;
    int n;
    cin >> n;
    int l = sizeof(sf)/sizeof(int);
    for(int i =0; i < l; i++){
        if (n%sf[i] == 0){
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;



    

}