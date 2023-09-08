//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    int solve(int arr[],int n ,int i,int prev ) {
        if( i == n ) {
            return 0;
        }
        
        int incl = 0;
        if( prev == - 1 || abs(arr[i] - arr[prev]) == 1) {
            incl = 1 + solve(arr,n,i+1,i); 
        }
        
        int excl = 0 + solve(arr,n,i+1,prev);
        
        return max(incl , excl);
    }
public:
    int longestSubsequence(int N, int A[])
    {
      return solve(A,N,0,-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends