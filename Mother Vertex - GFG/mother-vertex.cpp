//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    private:
    void dfs(int start,vector<int>adj[],vector<int>&vis,stack<int>&s) {
        vis[start] = 1;
        for(auto x: adj[start]) {
            if(!vis[x]) {
                dfs(x,adj,vis,s);
            }
        }
        
        s.push(start);
    }
    
    void check(int start,int &cnt,vector<int>&vis,vector<int>adj[]) {
         vis[start] = 1;
         cnt++;
        for(auto x: adj[start]) {
            if(!vis[x]) {
                check(x,cnt,vis,adj);
            }
        }
    }
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<int>vis(V,0);
	    stack<int>s;
	    for(int i = 0 ;i <V;i++) {
	        if(!vis[i]) {
	            dfs(i,adj,vis,s);
	        }
	    }
	    
	    for(int i = 0 ; i< V;i++) {
	        vis[i] = 0;
	    }
	    int ans = 0;
	    
	    check(s.top(),ans,vis,adj);
	    if(ans == V) 
	    return s.top();
	    
	    return -1;
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
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends