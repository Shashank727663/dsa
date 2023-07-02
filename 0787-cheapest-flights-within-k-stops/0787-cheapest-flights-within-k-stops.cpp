class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<int>dist(n,1e9);
       dist[src] = 0;
       for(int i=0;i<=k;i++) {
           vector<int>temp = dist;
           for( auto &x : flights) {
               int u = x[0];
               int v = x[1];
               int w  = x[2];

               temp[v] = min(temp[v] , w + dist[u]);
           }

           dist =  temp;
       }


       if( dist[dst] == 1e9) {
           return -1;
       }

       return dist[dst];
    }
};