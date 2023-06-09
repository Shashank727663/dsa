//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   private:
   bool bfs(int start ,int V ,vector<int> adj[],int col[]) {
       queue<int> q;
       q.push(start);
       col[start] =0;
       while(!q.empty()) {
           int temp = q.front();
           
           q.pop();
           
           for(auto x : adj[temp]) {
               if(col[x] == -1) {
                   col[x] = !col[temp];
                   q.push(x);
               }
               
               else if( col[x] == col[temp]  ) {
                   return false;
               }
           }
       }
       
       return true;
   }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    int col[V];
	    for(int i=0;i<V;i++) {
	        col[i] =-1;
	    }
	    
	    for(int i=0;i<V;i++) {
	        if(col[i] == -1) {
	            if(bfs(i,V,adj,col)== false) {
	                return false;
	            }
	        }
	    }
	    
	    return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends