//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void dfs(int src , int V , vector<int>adj[],vector<int>&vis,vector<int>&ans) {
        vis[src] = 1;
        ans.push_back(src);
        
        for(auto x: adj[src]) {
            if(!vis[x] ) {
                dfs(x,V,adj,vis,ans);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        vector<int>ans;
        for(int i = 0 ;i<V;i++) {
            if(!vis[i]) {
                dfs(i,V,adj,vis,ans);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends