//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{
    
    private:
    bool solve(vector<int>&arr, int sum  , int target , int i , vector<vector<int>>& dp) {
        if( sum == target ) {
            return true;
        }
        
        if( i >= arr.size() || sum > target) {
            return false;
        }
        if (dp[i][sum] != -1) {
        return dp[i][sum];
    }

        // incl 
        bool incl = solve(arr,sum + arr[i],target,i+1,dp);
        // excl
        bool excl =   solve(arr,sum ,target,i+1,dp);
        
            return dp[i][sum] = incl || excl;

    }
public:
int dp[101][101];
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        
            vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

        return solve(arr,0,sum,0,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends