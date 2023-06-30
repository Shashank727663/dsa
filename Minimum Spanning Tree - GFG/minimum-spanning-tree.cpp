//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int ans  = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>vis(V,0);
        
        pq.push({0,0});
        // wt ,node 
        
        while(!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            
            int weight = temp.first;
            int node = temp.second;
            
            if(vis[node] == 1) {
                continue;
            }
            
            vis[node] = 1;
            ans =ans + weight;
            
            for(auto x:adj[node] ) {
                int adjnode = x[0];
                int wt = x[1];
                if(!vis[adjnode]) {
                    pq.push( { wt ,adjnode});
                }
            }
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends