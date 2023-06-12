//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	string removeDups(string st) 
	{
	    // Your code goes here
	    set<char>s;
	    string ans;
	    for(auto x : st) {
	        if(s.find(x) == s.end()) {
	            s.insert(x);
	            ans.push_back(x);
	        }
	    }
	     return ans;
	     
	}
};

//{ Driver Code Starts.


int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   		
   		Solution ob;
   		cout << ob.removeDups(s) << "\n";
   		
   	}

    return 0;
}
// } Driver Code Ends