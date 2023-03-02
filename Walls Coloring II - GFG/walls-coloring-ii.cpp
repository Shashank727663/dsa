//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
   int minCost(vector<vector<int>>& costs) {
    const int n = costs.size(), k = costs[0].size();
    const int INF = 1e9;

    int min_cost = INF, min_second_cost = INF;
    int prev_color = -1, prev_color_index = -1;

    // Find the minimum and second minimum cost of coloring the first wall
    for (int i = 0; i < k; i++) {
        if (costs[0][i] < min_cost) {
            min_second_cost = min_cost;
            min_cost = costs[0][i];
            prev_color = i;
            prev_color_index = 0;
        } else if (costs[0][i] < min_second_cost) {
            min_second_cost = costs[0][i];
        }
    }

    // If there is only one wall, return the minimum cost of coloring it
    if (n == 1) {
        return min_cost;
    }

    // Find the minimum cost of coloring the remaining walls
    for (int i = 1; i < n; i++) {
        int cur_min_cost = INF, cur_min_second_cost = INF;
        int cur_prev_color = -1, cur_prev_color_index = -1;

        for (int j = 0; j < k; j++) {
            int cost = costs[i][j];
            int min_cost_without_same_color = min_cost;
            if (j == prev_color) {
                min_cost_without_same_color = min_second_cost;
            }

            int total_cost = min_cost_without_same_color + cost;

            if (total_cost < cur_min_cost) {
                cur_min_second_cost = cur_min_cost;
                cur_min_cost = total_cost;
                cur_prev_color = j;
                cur_prev_color_index = i;
            } else if (total_cost < cur_min_second_cost) {
                cur_min_second_cost = total_cost;
            }
        }

        // If there is no way to color the walls without coloring two adjacent walls the same color
        if (cur_min_cost == INF) {
            return -1;
        }

        // Update the minimum and second minimum costs for the current wall
        min_cost = cur_min_cost;
        min_second_cost = cur_min_second_cost;
        prev_color = cur_prev_color;
        prev_color_index = cur_prev_color_index;
    }

    // Return the minimum cost of coloring all the walls
    return min_cost;
}

};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends