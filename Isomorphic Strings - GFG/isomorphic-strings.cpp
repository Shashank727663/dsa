//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        if(str1.length() != str2.length()) {
            return false;
        }
        
        map<char,int>mp1;
        map<char,int>mp2;
        
        for(int i=0;i<str1.length();i++) {
            if(mp1.find(str1[i]) != mp1.end()) {
                if(mp1[str1[i]] != str2[i]) {
                    return false;
                }
            }
            
            
            else if (mp2.find(str2[i]) != mp2.end()) {
                if( mp2[str2[i]] !=  str1[i]) {
                    return false;
                }
            }
            
            
            mp1[str1[i]] = str2[i];
            mp2[str2[i]] = str1[i];
        }
        
        return true;
      }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends