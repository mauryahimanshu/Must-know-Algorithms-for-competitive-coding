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

vector<int> bottomView(Node *root) 
{ 
    
    vector<int> v;
    if (!root) 
        return v; 
  
    
    map < int,vector<int> > m; 
    int hd = 0; 
  
    
    
    queue<pair<Node*, int> > que; 
    que.push(make_pair(root, hd)); 
  
     while (!que.empty()) 
     { 
        
        pair<Node *,int> temp = que.front(); 
        que.pop(); 
        hd = temp.second; 
        Node* node = temp.first; 
  
        
        m[hd].push_back(node->data); 
  
        if (node->left != NULL) 
            que.push(make_pair(node->left, hd-1)); 
        if (node->right != NULL) 
            que.push(make_pair(node->right, hd+1)); 
    } 
  

    map< int,vector<int> > :: iterator it; 
    for (it=m.begin(); it!=m.end(); it++) 
    { 
        int j=0;
        for (int i=0; i<it->second.size(); ++i) 
            j= it->second[i]; 
        v.push_back(j);
    } 
    return v;
} 


