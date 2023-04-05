//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int n, vector<int> arr) {
        // Code here
        int ans=0;
        unordered_map<int,int>map;
        sort(arr.begin(),arr.end());
        for(auto x:arr){
            map[x]++;
        }
        
        for(int i=0;i<n;i++){
            if(map[arr[i]]>=2){
                ans++;
                continue;
                
            }
            
            for(int j=0;arr[j]<arr[i];j++){
                if(arr[i] % arr[j] == 0 ){
                    ans++;
                    break;
                }
            }
            
            
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends