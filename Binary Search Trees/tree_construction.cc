// #include "bits/stdc++.h"

// using namespace std;

// // struct bst {
// //     int value;
// //     bst *left, *right;

// //     bst(int value) {
// //         this->value = value;
// //         left = right = NULL;
// //     }
// // };

// // int place(bst* root, bst*node){
// //     if(node -> value <= root-> value){
// //         if (root-> left == NULL){
// //             root-> left = node;
// //             return root-> value;
// //         }
// //         return (place(root->left, node));
// //     }
// //     if (root-> right == NULL){
// //         root-> right = node;
// //         return root-> value;
// //     }else{
// //         return (place(root->right, node));
// //     }
// // }

// int main(){
//     int n;
//     cin>> n;
//     vector<int> mnQ, mxQ;
//     int c; cin >> c;
//     n--;
//     mnQ.push_back(c); mxQ.push_back(c);
//     while(n--){
//         cin >> c;
//         if(c < mnQ[mnQ.size()-1]){
//             int i = 0;
//             while(i < mnQ.size()){
//                 if (mnQ[i] > c){
//                     break;
//                 }
//                 i++;
//             }
//             printf("%d ", mnQ[i]);
//             mnQ[i]=c;
//             i = 0;
//             while(i < mxQ.size()){
//                 if (c > mxQ[i])break;
//                 i++;
//             }
//             // if(i!= 0)i--;
//             mxQ.insert(mxQ.begin() +i, c);

//         }else {
//             int i = 0;
//             while(i < (mxQ.size())){
//                 if (mxQ[i] < c){
//                     break;
//                 }
//                 i++;
//             }

//             printf("%d ", mxQ[i]);
//             mxQ[i]=c;

//             i = 0;
//             while(i < mnQ.size() ){
//                 if (c > mnQ[i])break;
//                 i++;
//             }
//             i++;            
//             mnQ.insert(mnQ.begin() + i, c);
//         }
//     }
//     printf("\n");
// }
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
 
int main(){
 
    long n; scanf("%ld", &n);
    std::set<long> s;
    std::map<long, std::pair<long, long> > m;
 
    long a; scanf("%ld", &a); s.insert(a); m[a] = std::make_pair(-1, -1);
 
    for(long p = 1; p < n; p++){
        scanf("%ld", &a);
        std::set<long>::iterator it = s.upper_bound(a);
        if(it == s.end() || m[*it].first >= 0){--it; m[*it].second = a;}
        else{m[*it].first = a;}
        s.insert(a); m[a] = std::make_pair(-1, -1);
        printf("%ld ", *it);
    }
 
    puts("");
 
    return 0;
}
