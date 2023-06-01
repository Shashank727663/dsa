//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> nums, int n) {
        // code here
     
        sort(nums.begin(),nums.end());
        int y;
        // r --> repeating 
        // y --> missing 
        int r =1;
       for(int i=0;i<nums.size();i++) {
           if(nums[i] == r) {
               r++;
           }
       }
       
       for(int i=1;i<nums.size();i++) {
           if(nums[i] == nums[i-1]){
               y = nums[i];
           }
       }
        
        return {y,r};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends