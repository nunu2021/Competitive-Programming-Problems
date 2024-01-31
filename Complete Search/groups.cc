#include "bits/stdc++.h"

using namespace std;

int main(){
    int c;
    cin >> c;

    while(c--){
        int nc;
        cin >> nc;
        int arr[nc][5];
        for(int i = 0; i < nc; i++){
            scanf("%d %d %d %d %d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3], &arr[i][4]);
        }
        int flag = 0;
        for (int i =0; i< 5; i++){
            for (int j = i+1; j <5; j++){
               
                int day1 = i; int day2 = j;
                int n1=0, n2 =0, c= 0;
                for (int k = 0; k < nc; k++){
                    if(arr[k][day1] == 1) n1++;
                    if(arr[k][day2] == 1) n2++;
                    if (arr[k][day2] == 0 && arr[k][day1] == 0) c++;
                }
                if(n1 >= nc/2 && n2 >= nc/2 && c == 0){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag){printf("YES\n");}else{printf("NO\n");}
    }
}