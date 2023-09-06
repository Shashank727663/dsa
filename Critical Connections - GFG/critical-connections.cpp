//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
 
    int timer=1;
    
    void dfs(int node,int parent,vector<int> &vis,vector<int> adj[],int tin[],int low[],vector<vector<int>> &bridges)
    {
        vis[node]=1;
        tin[node]=timer;
        low[node]=timer;
        timer++;
        for(auto it:adj[node])
        {
            if(parent==it)
                continue;
            if(vis[it]==0)
            {
                dfs(it,node,vis,adj,tin,low,bridges);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node])
                {
                    if(it>node)
                    bridges.push_back({node,it});
                    else
                    bridges.push_back({it,node});
                }
            }
            else
                low[node]=min(low[node],low[it]);
        }
    }
vector<vector<int>>criticalConnections(int V, vector<int> adj[]){
    
    vector<int> vis(V,0);
    int tin[V];
    int low[V];
    vector<vector<int>> bridges;
    dfs(0,-1,vis,adj,tin,low,bridges);
    sort(bridges.begin(),bridges.end());
    return bridges;
    // Code here
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
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends