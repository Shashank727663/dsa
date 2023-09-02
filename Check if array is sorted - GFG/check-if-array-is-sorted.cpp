//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool arraySortedOrNot(int arr[], int n) {
        // code here
        vector<int>ans1;
        vector<int>ans2;
        
        for(int i = 0 ; i < n ; i ++ ) {
            ans1.push_back(arr[i]);
            ans2.push_back(arr[i]);
        }
        
        
        sort(ans1.begin(),ans1.end());
        
        
        return (ans1 == ans2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        bool ans = ob.arraySortedOrNot(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends