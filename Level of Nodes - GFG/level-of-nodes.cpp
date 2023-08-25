//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    queue<pair<int,int>>q;
	    q.push({ 0 , 0 });
	    vector<int>vis(V,0);
	    
	    while(!q.empty()) {
	        int node = q.front().first;
	        int lvl = q.front().second;
	        q.pop();
	        if(node == X) {
	            return lvl;
	        }
	        
	        for(auto x: adj[node]) {
	            if(!vis[x] ) {
	                vis[x] = 1;
	                q.push({ x, lvl + 1});
	            }
	        }
	    }
	    
	    
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends