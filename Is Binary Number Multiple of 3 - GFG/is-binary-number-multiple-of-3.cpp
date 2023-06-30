//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    
	    int sum  = 0;
	    
	    int n = s.length();
	    
	    for(int i=0;i<n;i++) {
	        if(s[i] == '1' ) {
	            if( i % 2 == 0 ) {
	                sum = sum + 1;
	            }
	            else {
	                sum = sum + 2;
	            }
	        }
	    }
	    
	    
	    return (sum %3) == 0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends