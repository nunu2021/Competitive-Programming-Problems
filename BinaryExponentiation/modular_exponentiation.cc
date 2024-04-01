#include "../bits/stdc++.h"

using namespace std;
int t, mod, a, b;
int main(){
    cin >> t >> mod;

    while(t--){
        cin >> a >> b;
        printf("Whatttttt %d %d \n", a, b);
        long long int curr = 1;
        int a_pw = a;
        while(b){
            printf("Whatttttt before %d %d %d\n", a, b, curr);
            int power = b&1;
            curr *= pow((a_pw % mod), power);
            curr %= mod;
            a_pw *= a_pw;
            b >>= 1;
            printf("Whatttttt after %d %d %d\n", a, b, curr);
        }
        int bruh = curr % mod;
        cout << bruh << endl;

    }
    return 0;
}