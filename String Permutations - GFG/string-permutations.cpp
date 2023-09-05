//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    void solve(string s , int i , vector<string>&ans) {
        if(i >= s.length()) {
            ans.push_back(s);
            return;
        }
        
        for(int x = i ; x < s.size();x++) {
            swap(s[i],s[x]);
            solve(s,i + 1, ans);
            //backracking 
            swap(s[i],s[x]);
        }
    }
    
    public:
    //Complete this function
    
    vector<string> permutation(string S)
    {
        //Your code here
                vector<string> ans;
        int index = 0;
        solve(S , index , ans);
        sort(ans.begin() , ans.end());
        return ans;

    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends