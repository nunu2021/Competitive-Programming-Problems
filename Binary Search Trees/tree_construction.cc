#include "bits/stdc++.h"

using namespace std;

struct bst {
    int value;
    bst *left, *right;

    bst(int value) {
        this->value = value;
        left = right = NULL;
    }
};

int place(bst* root, bst*node){
    if(node -> value <= root-> value){
        if (root-> left == NULL){
            root-> left = node;
            return root-> value;
        }
        return (place(root->left, node));
    }
    if (root-> right == NULL){
        root-> right = node;
        return root-> value;
    }else{
        return (place(root->right, node));
    }
}

int main(){
    int i;
    cin >> i;
    int c = 0;
    bst * root;
    while(i--){
        int a;
        cin >>a;
        bst* node = new bst(a);
        if( c == 0){
            root = node;
        }else{
            // add to the tree and print out parent
            int y = place(root, node);
            printf("%d ", y);
        }
        c++;
    }
    printf("\n");
}

