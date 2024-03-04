#include "bits/stdc++.h"

using namespace std;

int t, n, temp;
int main(){
    cin >> t;
    while(t--){
        cin >> n;

        map<int, int> a;
        vector<int> b, c;

        for(int i = 0; i < n; i++){cin >> temp; a[temp] = i;}
        for(int i = 0; i< n; i++){cin >> temp; b.push_back(temp);}

        for(int i = 0; i < n; i++){
            c.push_back(a[b[i]]);
        }

        vector<int> ans;
        ans.push_back(c[0]);
        for(int i = 1; i< n; i++){
            if(c[i] > ans[ans.size()-1]){
                ans.push_back(c[i]);
            }else{
                int begin = 0; int end = ans.size()-1;
                int mid = (begin + end)/2;
                while(begin < end){
                    mid = (begin +end)/2;
                    if(c[i]>ans[mid]){
                        begin = mid +1;
                    }else{
                        end = mid;
                    }
                }
                ans[mid] = c[i];
            }
        }
        int fin = (n-ans.size())*2;
        cout << fin << '\n';
    }

}






// #include "bits/stdc++.h"
// using namespace std;
// int n, l, temp;
// int main(){
//     cin >> n;
//     while(n--){
//         map<int, int> a;
//         vector<int> b;
//         vector<int> c;
//         cin >> l;

//         for(int i = 0; i < l; i++){cin >> temp; a[temp]=i;}
//         for (int i =0; i< l; i++){cin >> temp; b.push_back(temp);}
        
//         for(int i = 0; i < l; i++){
//             int index = a[b[i]];
//             c.push_back(index);
//         }  
//         vector<int> ans;
//         ans.push_back(c[0]);
//         for(int i = 1; i < l; i++){
//             if(c[i] > ans[ans.size()-1]){
//                 ans.push_back(c[i]);
//             }else{
//                 // binary search to find the largest number smaller than c[i]
//                 int begin = 0; int e = ans.size() -1;
//                 int mid = (begin + e)/2;
                
//                 while(begin < e){
//                     mid = (begin + e)/2;
//                     if(c[i]> ans[mid]){
//                         begin = mid+1;
//                     }else{
//                         e = mid;
//                     }
//                 }
//                 ans[mid] = c[i];
//             }   
//         }
//         int comp  = (l - ans.size()) * 2;
//         cout  << comp << "\n";
//     }
// }