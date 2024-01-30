#include <stdio.h>

int main(){

    int add_sum = 0;
    int sub_sum = 0;
    while(1){
        add_sum =0 ;
        sub_sum = 0;
        int add, sub;
        scanf("%d %d", &add, &sub);
        if (add == 0 && sub == 0){
            return 0;
        }
        
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
