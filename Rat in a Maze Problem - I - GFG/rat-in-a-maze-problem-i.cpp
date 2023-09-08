//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
   private:
    void solve(vector<vector<int>> &m, int n, int i, int j, vector<string> &ans, string &s, vector<vector<int>> &vis) {
        if (i < 0 || i >= n || j < 0 || j >= n || m[i][j] == 0 || vis[i][j] == 1) {
            return; // Invalid or visited cell
        }

        if (i == n - 1 && j == n - 1) {
            ans.push_back(s);
            return;
        }

        vis[i][j] = 1; // Mark the current cell as visited

        s.push_back('D');
        solve(m, n, i + 1, j, ans, s, vis);
        s.pop_back();

        s.push_back('L');
        solve(m, n, i, j - 1, ans, s, vis);
        s.pop_back();

        s.push_back('R');
        solve(m, n, i, j + 1, ans, s, vis);
        s.pop_back();

        s.push_back('U');
        solve(m, n, i - 1, j, ans, s, vis);
        s.pop_back();

        vis[i][j] = 0; // Mark the current cell as unvisited (backtrack)
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string s = "";
        vector<vector<int>> vis(n, vector<int>(n, 0)); // Initialize vis with dimensions n x n
        if (m[0][0] != 0) {
            solve(m, n, 0, 0, ans, s, vis);
        }
        return ans;
    }
};


    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends