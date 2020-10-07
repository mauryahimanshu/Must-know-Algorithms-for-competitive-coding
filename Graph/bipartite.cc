// C++ program to find out whether a 
// given graph is Bipartite or not 
#include <iostream> 
#include <queue> 
#define V 4 

using namespace std; 

// This function returns true if graph 
// G[V][V] is Bipartite, else false 
bool bfs(int src,vector<int> &vis,vector<vector<int>>& graph)
    {
        queue<pair<int,int>> que;
        que.push({src,0});
        
        while(que.size()!=0)
        {
            int size=que.size();
            while(size-- > 0)
            {
                pair<int,int> rvtx=que.front();
                que.pop();
                if(vis[rvtx.first]!=-1) // already visited(cycle).
                {
                    if(vis[rvtx.first]!=rvtx.second) // check for conflict.
                        return false;
                }
                vis[rvtx.first]=rvtx.second;
                int color=(rvtx.second+1)%2; //assigns colour in the form of digits
                for(int e : graph[rvtx.first])
                {
                    if(vis[e]==-1)
                    {
                        que.push({e,color});
                    }
                }
            }
        }
        
        return true;
    }
bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++)
        {
            if(graph[i].size()==0 || vis[i]!=-1)
                continue;
            if(!bfs(i,vis,graph))
                return false;
        }
        
        return true;
   }

// Driver program to test above function 
int main() 
{ 
	vector<vector<int>> G={{0, 1, 0, 1}, 
		{1, 0, 1, 0}, 
		{0, 1, 0, 1}, 
		{1, 0, 1, 0} 
	}; 

	isBipartite(G) ? cout << "Yes" : cout << "No"; 
	return 0; 
} 
