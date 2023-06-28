//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool dfs(int start , vector<int>&vis,vector<int>&st,vector<int>adj[]) {
        vis[start] = 1;
        st[start] = 1;
        for(auto x :adj[start]) {
            if(vis[x] == 0) {
                if( dfs(x,vis,st,adj) == true) {
                    return true;
                }
            }
            
            else if( st[x] == 1) {
                return true;
            }
        }
        
        
        st[start] = 0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0);
        vector<int>st(V,0);
        for(int i=0;i<V;i++ ) {
           if( vis[i] == 0 ) {
               if( dfs(i ,vis,st,adj) == true ) {
                   return true;
               }
           }
        }
        
        
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends