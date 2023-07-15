//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
    private:
        int solve(string &s ,string &r,int i ,int j , vector<vector<int>>&dp) {
        if( i == s.length() || j == r.length()) {
            return 0;
        }
        
        if(dp[i][j] != -1) {
            return  dp[i][j];
        }
        if(s[i] == r[j]) {
            return dp[i][j] = 1 + solve(s,r,i+1,j+1,dp);
        }
        
        return  dp[i][j] = max( 
            solve(s,r,i+1,j,dp),
            solve(s,r,i,j+1,dp));
            
    }
public:
    int findMinInsertions(string s){
        // code here
        string r = s;
        int n =s.length();
        vector<vector<int>>dp(n +1 ,vector<int>(n+1 , -1));
        reverse(s.begin() , s.end());
        return n - solve(s,r,0,0,dp);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends