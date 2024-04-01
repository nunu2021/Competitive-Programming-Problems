#include "bits/stdc++.h"

using namespace std;
string s, t;
int a = 1024;
int b = 999331;

int getHash(string s){
    int hash = 0;
    for(int i = 0; i < s.size(); i++){
        hash = (hash* a + s[i]) % b;
    }
    return hash;
}

int main(){
    cin >> s ;
    cin >> t;

    if (t.size() > s.size()){
        cout << 0 << endl;
        return 0;
    }else if(s == t){
        cout << 1 << endl;
        return 0;
    }

    int pow = 1;
    for(int i = 1;i < t.size(); i++){
        pow = (pow * a) % b;
    }

    int count = 0;
    int t_hash = getHash(t);
    int ss_hash = getHash(s.substr(0,t.size()));
    if (ss_hash == t_hash){
            count ++;
        }
    
    for(int i = 0; i < (s.size()-t.size()); i++){
        
        
        ss_hash = (((b + ss_hash) - ((pow*s[i])%b)) * a + s[i+t.size()]) %b;
       
        if (ss_hash == t_hash ){
            count ++;
        }
    }
    cout << count << endl;
    return 0;
}