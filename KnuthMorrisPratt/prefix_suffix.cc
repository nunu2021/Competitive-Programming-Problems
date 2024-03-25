#include "bits/stdc++.h"

using namespace std;

int main(){
    string s;
    cin >> s;
    string matched;
    int ii = 0;
    int i = 0;

    vector <int> ret ;
    while(i < s.size()){
       if(s[i] == s[ii] && (ii != i)){

            ii++;
            i++;
           ret.push_back(ii);
       }else {
            if(ii != 0){
                ii = ret[ii-1];
            }else{
                ii = 0;
                i++;
                ret.push_back(ii);
            }
       }
       
    }

    for(int j = 0; j < s.size();j++){
        cout << ret[j] << " ";
    }
    cout << endl;

    return 0;
}