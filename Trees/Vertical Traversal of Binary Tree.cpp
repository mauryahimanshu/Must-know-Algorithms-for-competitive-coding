#include <bits/stdc++.h>
using namespace std;


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

vector<vector <int>> verticalOrder(Node *root);


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


void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        
    	Node* root = buildTree(s);
    	
    	vector<vector <int>> res = verticalOrder(root);
    	for (vector<int> ar : res) 
	{
	   for(int ele: ar)
	     cout<<ele;
	   cout<<" "
	}
    }
	return 0;
}

int leftMinValue = 0;
int rightMaxValue = 0;
void width(Node* root, int lev) {
        if (root == NULL) return;

        leftMinValue = min(leftMinValue, lev);
        rightMaxValue = max(rightMaxValue, lev);

        width(root->left, lev - 1);
        width(root->right, lev + 1);
}

vector<vector<int>> verticalOrder(Node* root) 
{ 
   width(root, 0);
   int n = rightMaxValue - leftMinValue + 1;
   vector<vector<int>> ans(n,vector<int>()); 
    queue<pair<Node*,int>> que;
        que.push({root, -leftMinValue});

        while (que.size() != 0) {
            int size = que.size();
            while (size-- > 0) {
                pair<Node*,int> rpair = que.pop();
                ans[rpair.second].push_back(rpair.first->data);
                if (rpair.first->left != NULL) que.push({rpair.first->left, rpair.second - 1});
                if (rpair.first->right != NULL) que.push({rpair.first->right, rpair.second + 1});
            }
        }

        return ans;
} 

