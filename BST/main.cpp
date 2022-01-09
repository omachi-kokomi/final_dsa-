#include<iostream>
#include"bst.h"

int main(){
    int a[12] = {25, 20, 36, 10, 22, 30, 40, 5, 12, 28, 38, 48};
    int n = 12;
    NODE* root = createTree(a, 12);
    LRN(root);
    cout << endl;
    LRNNonRec(root);
    return 0;
}