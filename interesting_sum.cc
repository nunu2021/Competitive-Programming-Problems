#include "bits/stdc++.h"
#include <iostream>
using namespace std;

int main(){
    int cases;
    scanf("%d", &cases);
    for (int i = 0; i <cases; i++){
        int ln;
        scanf("%d", &ln);
        int max1 = 0;
        int max2 = 0;
        int min1 = 1000000000;
        int min2 = 1000000000;
        for (int j = 0; j< ln; j++){
            int v;
            cin >> v;
            if (v > max1) {max2 = max1; max1=v;}
            else if(v > max2) {max2 = v;}
            if (v < min1){min2 = min1; min1 = v;}
            else if (v < min2) min2 = v;
        }
        printf("%d\n", max1 + max2 - min1 - min2);
    }
}