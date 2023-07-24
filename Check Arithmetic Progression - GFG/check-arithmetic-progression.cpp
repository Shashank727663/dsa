//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    bool checkIsAP(int arr[], int n)
    {
        sort(arr , arr + n );
        set<int>s;
        for(int i = 1;i<n;i++) {
            int d  = abs( arr[i - 1] - arr[i]);
            s.insert(d);
        }
        
        if( s.size() == 1) {
            return 1;
        }
        
        return 0;
        
    }

};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
         (ob.checkIsAP(arr, n))? (cout << "YES" << endl) :
                       (cout << "NO" << endl);   
    }
 
  return 0;
}

// } Driver Code Ends