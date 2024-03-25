#include "bits/stdc++.h"

using namespace std;
int n, a, b;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while(n--){
        string ss;
        cin >> ss;
        string s = ss;
        if(s.length() == 0 || s.size()==1){
            cout << 0 << endl;
            continue;
        }
        int count = 0;
        for(int i = 1; i< s.size(); i++){
            if(s[i] == s[i-1] || (i>1 && s[i] == s[i-2])){
                s[i] = '*';
                count +=1;
            }   
        }
        cout << count << endl;
    }
   return 0;
}