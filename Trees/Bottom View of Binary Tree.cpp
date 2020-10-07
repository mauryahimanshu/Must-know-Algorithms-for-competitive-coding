#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> bottomView(Node *root);

Node* buildTree(string str)
{
    
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);


    Node* root = newNode(stoi(ip[0]));

    
    queue<Node*> queue;
    queue.push(root);

    
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        
        Node* currNode = queue.front();
        queue.pop();

        
        string currVal = ip[i];

        
        if(currVal != "N") {

            
            currNode->left = newNode(stoi(currVal));

            
            queue.push(currNode->left);
        }

        
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        
        if(currVal != "N") {

            
            currNode->right = newNode(stoi(currVal));

            
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

//CODE TO FIND THE BOTTOM VIEW FOR THE TREE
int leftMinValue = 0;
int rightMaxValue = 0;
void width(Node* root, int lev) {
        if (root == NULL) return;

        leftMinValue = min(leftMinValue, lev);
        rightMaxValue = max(rightMaxValue, lev);

        width(root->left, lev - 1);
        width(root->right, lev + 1);
}
vector<int> bottomView(Node *root) 
{ 
    if (!root) 
        return {};
    width(node, 0);
    vector<int> ans(rightMaxValue - leftMinValue + 1,0);
    queue<pair<Node*,int>> que;
    que.push({root, -leftMinValue});
    while (que.size() != 0) {
            int size = que.size();
            while (size-- > 0) {
                pair<Node*,int> rpair = que.pop();
                ans[rpair.second] = rpair.first->data;
                if (rpair.first->left != NULL) que.push({rpair.first->left, rpair.second - 1});
                if (rpair.first->right != NULL) que.push({rpair.first->right, rpair.second + 1});
            }
        }
    return ans;
    
} 

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector <int> res = bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
