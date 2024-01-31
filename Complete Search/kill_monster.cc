#include "bits/stdc++.h"

using namespace std;

int main(){
    int c;
    scanf("%d", &c);

    while(c--){
        unsigned long long int hc, dc, hm, dm, k, w, a;
        scanf("%lld %lld \n %lld %lld \n %lld %lld %lld", &hc, &dc, &hm, &dm, &k, &w, &a);
        unsigned long long int flag = 0;
        unsigned long long int mt = ((hc/dm) + ((hc%dm)!=0));
        unsigned long long int ct = ((hm/dc) + ((hm%dc)!=0));
        for (int i =0; i < k+1; i++){
            unsigned long long int weap = i;
            unsigned long long int heal = k - i;

            unsigned long long int new_hc = hc + heal*a;
            unsigned long long int new_dc = dc + weap*w;

            unsigned long long int mt = (new_hc / dm);
            if (new_hc % dm != 0) mt++;
            unsigned long long int ct = (hm/new_dc) ;
            if (hm%new_dc != 0) ct++;

            if(ct <= mt ){
                flag = 1;
                break;
            }
        } 
        if(flag){printf("YES\n");}else{printf("NO\n");}
        
    }
   
}