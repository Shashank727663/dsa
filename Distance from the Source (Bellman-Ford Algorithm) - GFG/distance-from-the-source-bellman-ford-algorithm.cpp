//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int s) {
       vector<int>dist(V,1e8);
       dist[s] = 0;
       
       for(int i=0;i<V;i++) {
          for(auto x : edges){
              // inittial node 
              int u = x[0];
              // adjacent node
              int v  = x[1];
              //weight 
              
              int w = x[2];
              
              if(dist[v]  > dist[u] + w) {
                  dist[v] = dist[u] + w;
              }
              
          }
           
       }
       
       // nth iteration
       
       for(auto x : edges) {
           int u  = x[0];
           int v  = x[1];
           int wt = x[2];
           
           if(dist[v] > dist[u] + wt) {
               return {-1};
           }
       }
       
       return dist;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends