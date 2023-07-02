//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // 1 graph creation 
        vector<pair<int,int>>adj[n];
        // nextnode , cost 
        for(auto x : flights) {
            adj[x[0]].push_back({ x[1] , x[2]});
            
        }
        
        // queue 
        queue<pair<int,pair<int,int>>>q;
        // stops , node , weight 
        
        
        q.push({ 0 , { src , 0}});
        vector<int>dist(n,1e8);
        dist[src] = 0;
        
        while(!q.empty()) {
            int node = q.front().second.first;
            int stops = q.front().first;
            int wt  = q.front().second.second;
            q.pop();
            if(stops > K) {
                continue;
            }
            
            
            for(auto x : adj[node]) {
                int newnode = x.first;
                int newcost = x.second;
                
                if(dist[newnode] > newcost + wt && stops <= K ) {
                    dist[newnode] = newcost + wt;
                    q.push( { stops + 1 , { newnode ,  wt + newcost}});
                }
            }
        }
        
        if( dist[dst] == 1e8) {
            return -1;
        }
        
        
        return dist[dst];
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends