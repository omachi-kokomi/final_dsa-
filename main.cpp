#include<iostream>
#include<vector>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

node* createNode(int x){
    node* p =  new node;
    p->data = x;
    p->right = NULL;
    p->left = NULL;
}

void insert(node*& root, int x){
    if (root == NULL){
        root = createNode(x);
        return;
    }
    if (root->data < x) insert(root->right, x);
    if (root->data > x) insert(root->left, x);
}

node* initBST(){
    node* root = NULL;
    return root;
}

int countNode(node* root){
    if (root == NULL) return 0;
    return 1 + countNode(root->left) + countNode(root->right);
}
int res1 = -1, res2 = -1;

int k = 0;
void findMedian(node* root, int nnode){
    if (root == NULL) return;
    findMedian(root->left, nnode);
    k++;
    if (nnode % 2 == 0){
        if (k == (nnode/2)) res1 = root->data;
        if (k == (nnode/2 + 1)) res2 = root->data;
    }
    else{
    if (k == (nnode + 1)/2) {res1 = root->data;  res2 = root->data;}
    }  
    findMedian(root->right, nnode);
}

int main(){
    vector<int> a = {4, 7, 2, 3, 10, 1, 5, 11};
    node* root = initBST();
    for(int i = 0; i < a.size(); i++) insert(root,  a[i]);
    int nnode = countNode(root);
    findMedian(root, nnode);
    cout << (float)(res1 + res2) / 2;
    return 0;
}