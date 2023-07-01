//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        int vis[n][m];
        queue < pair < pair < int, int > , int >> q;
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                    
                }
                else{
                     vis[i][j] = 0;
                }
                
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        
        int time=0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        //bfs traversal 
        int cnt=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            time=max(time,t);
            //for 4 neighbours
            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                //checking for the validity
                if(nrow>=0 && nrow< n && ncol>=0 && ncol<m &&  vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                     q.push({{nrow, ncol}, t + 1}); 
            // mark as rotten
            vis[nrow][ncol] = 2;
            cnt++;
                }
            }
            q.pop();
            
        }
        
          if (cnt != fresh) return -1;
          return time;
        
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends