#include "../bits/stdc++.h"

typedef unsigned long long ull;
using namespace std;
int n, l;

int main(){
    cin >> n;

    while(n--){
        cin >> l;
        int ll = l;
        ull v;
        ull prod = 1;
        while(ll--){
            cin >> v;
            prod*=v;
        }
        

        if(prod == 0){
            cout << 0 << endl;
            continue;
        }

        

        int fin = 0;
        int i;
        bool cont = false;
        for(i = l; i >0; i--){
           if(prod %2){
            break;
           }
           prod =prod/2; 
        }

        int count = (l)/2;

        while(i-- > 0){
            if(prod%2){
                if(count == 0){
                    fin = -1;
                    break;
                }
                cout << "i need to change NOW " << (((count) * 2)) << endl;
                prod*= (((count) * 2));
                fin++;
                count--;
            }
            prod = prod/2;
        }

        cout << "skjdfhqlugfljashfau"<<fin  << endl;
    }
    
    return 0;
}