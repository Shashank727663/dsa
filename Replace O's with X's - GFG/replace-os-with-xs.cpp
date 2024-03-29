//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        int dr[]={1,0,-1,0};
        int dc[]={0,1,-0,-1};
        queue<pair<int,int>>q;
        vector<vector<char>>dis(n , vector<char>(m , 'X'));
        vector<vector<int>>vis(n , vector<int>(m , 0));
       
        
        for(int i = 0 ;i < n ;i++) {
            for(int j = 0 ; j < m;j++) {
                if( i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    if(mat[i][j]=='O')
                    {
                        vis[i][j]=1;
                        q.push({i,j});
                        dis[i][j]='O';
                    }
                }
            }
        }
        
        
        while(!q.empty()) {
            int r = q.front().first;
            int c =q.front().second;
            q.pop();
            
            for(int i = 0 ; i <4 ;i++ ) {
                int drow = r + dr[i];
                int dcol = c + dc[i];
                
                if(drow >= 0 && drow < n && dcol >= 0 && dcol < m && !vis[drow][dcol] && mat[drow][dcol] == 'O') {
                    
                        vis[drow][dcol]=1;
                        q.push({drow,dcol});
                        dis[drow][dcol]='O';
                }
            }
        }
        
        return dis;

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends