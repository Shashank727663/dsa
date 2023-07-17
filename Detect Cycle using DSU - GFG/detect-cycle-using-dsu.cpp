//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    bool dfs(int src ,int parent ,vector<int>&vis,vector<int>adj[])  {
        vis[src] = 1;
        for(auto x : adj[src]) {
            if(!vis[x]) {
                if(dfs(x,src,vis,adj) == true) {
                    return true;
                }
            }
            
            else if(x != parent ) {
                return true;
            }
        }
        
        return false;
    }
    public:
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	   vector<int>vis(V,0);
	   for(int i=0;i<V;i++) {
	       if(!vis[i]) {
	           if(dfs(i,-1,vis,adj) == true) {
	               return 1;
	           }
	       }
	   }
	   
	   return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends