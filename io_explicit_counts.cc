#include <stdio.h>
int main(){
    int cases = 0;
    scanf("%d", &cases);
    int add_sum = 0;
    int sub_sum = 0;
    for(int i = 0; i < cases; i++){
        add_sum =0 ;
        sub_sum = 0;
        int add, sub;
        scanf("%d %d", &add, &sub);
        
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
    if(cases == 0)printf("0\n");
}
