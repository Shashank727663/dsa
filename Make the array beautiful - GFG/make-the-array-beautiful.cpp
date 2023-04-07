//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        for(int i = 0; i < arr.size() - 1; i++)
        {
            if((arr[i] > 0 && arr[i + 1] < 0) || (arr[i] < 0 && arr[i + 1] > 0) || (arr[i] < 0 && arr[i + 1] == 0) || (arr[i] == 0 && arr[i + 1] < 0))
            {
                arr.erase(arr.begin() + i);
                arr.erase(arr.begin() + i);
                i = i - 2;
            }
            if(i < -1)
            {
                i = -1;
            }
            if(arr.size() == 0)
            {
                break;
            }
        }
        return arr;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends