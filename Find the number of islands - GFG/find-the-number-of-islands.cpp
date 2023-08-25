//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void bfs(int r , int c , vector<vector<int>>&vis,vector<vector<char>>&grid) {
        vis[r][c] = 1;
           int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        q.push({ r , c });
        
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop();
            
            for(int delr = - 1 ; delr <= 1 ;delr++) {
                for(int delc = - 1 ; delc <= 1 ;delc++) {
                    int nr = row + delr;
                    int nc = col + delc;
                    
                    if(nr >= 0 && nr <n && nc >=0 && nc < m && grid[nr][nc] == '1' && !vis[nr][nc]) {
                        vis[nr][nc] = 1;
                        q.push( { nr , nc });
                    }
                    
                    
                }
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n , vector<int>(m,0));
        int ans = 0;
        for(int i = 0;i <n ;i++) {
            for(int j = 0 ;j < m ;j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    ans++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends