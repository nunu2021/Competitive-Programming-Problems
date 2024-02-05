#include "bits/stdc++.h"

using namespace std;

int main(){
    char input[8];
    long min = 1;
    long max = pow(10, 18);
    long val = 1;

    while (1){

        printf("%ld\n", val);
        fflush(stdout);
        scanf("%s", input);
        if(strcmp(input, "HIGHER")== 0){
            min = val;
        }else if(strcmp(input, "LOWER")==0 ){
            max = val;
        }else{
            break;
        }
        val = ((min + max) /2) + 1;
    }
    return 0;
    
}