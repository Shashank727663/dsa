//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User-function template for C++

// Complete the function
// n: Input n
// Return True if the given number is a lucky number else return False

class Solution{
    private:
    bool check(int n ,int i) {
        if(n < i ) {
            return true;
        }
        
        if( n % i == 0 ) {
            return false;
        }
        
        return check(n - n / i , i + 1);
    }
public:
    bool isLucky(int n) {
        // code here
        return check(n,2);
    }
};

//{ Driver Code Starts.
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        Solution obj;
        //calling isLucky() function
        if(obj.isLucky(n))
            cout<<"1\n";//printing "1" if isLucky() returns true
        else
            cout<<"0\n";//printing "0" if isLucky() returns false
    }
    
}
// } Driver Code Ends