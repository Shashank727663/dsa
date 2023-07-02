//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        
        // using bellman ford algorithm 
        
        vector<int>dist(n,1e8);
        
        dist[src] = 0;
        for(int i = 0 ; i<=K;i++) {
            
            // using an extra space for data consistency
            vector<int> temp = dist;
            for(auto x : flights) {
                int  u  =x[0];
                int v = x[1];
                int w = x[2];
                temp[v] =  min ( temp[v] , dist[u] + w);
              
            }
            
            dist = temp;
            // swapping the vectors
        }
        
        
        if(dist[dst] == 1e8) {
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