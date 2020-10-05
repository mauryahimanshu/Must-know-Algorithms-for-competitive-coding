#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void preOrder(Node* node) {
    if (node == NULL) return;

    printf("%d ", node->data);    
    preOrder(node->left);
    preOrder(node->right);
}



Node *buildUtil(int in[], int post[], int instart, int inend, int postend)
{
    if(postend<0 || instart>inend) return NULL;
    Node* root=new Node(post[postend]);
    int i;
    for(i=instart;i<inend;i++)
    {
        if(in[i]==root->data) break;
    }
    root->left=buildUtil(in,post,instart,i-1,postend-1+i-inend);
    root->right=buildUtil(in,post,i+1,inend,postend-1);
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    return buildUtil(in, post, 0, n-1, n-1);
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
