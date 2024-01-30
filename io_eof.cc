#include <stdio.h>

int main(){

    int add_sum, sub_sum, add, sub;

    while(scanf("%d %d", &add, &sub) != EOF){
        add_sum =0 ;
        sub_sum = 0;
       
        int val;
        for (int j = 0; j<add; j++){
            scanf("%d", &val);
            add_sum+=val;
        }
        
        for (int j = 0; j<sub; j++){
            scanf("%d", &val);
            sub_sum+=val;
        }
        printf("%d\n", add_sum - sub_sum);
        
    }
}
