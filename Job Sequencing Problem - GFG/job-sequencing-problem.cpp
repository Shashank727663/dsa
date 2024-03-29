//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool cmp( Job a , Job b) {
        return a.profit > b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,cmp);
        
        int maxdeadline = 0;
        for(int i = 0;i<n;i++) {
            maxdeadline = max(maxdeadline , arr[i].dead);
        }
        
        int maxprofit = 0;
        int count = 0;
        vector<int>timeline(n+1,-1);
        for(int  i = 0;i<n;i++ ) {
            int crprofit = arr[i].profit;
            int crdead = arr[i].dead;
            int crid = arr[i].id;
            
            for(int k = crdead;k>0;k--) {
                if(timeline[k] == - 1) {
                    count++;
                    maxprofit = maxprofit + crprofit;
                    timeline[k] = crid;
                    break;
                }
            }
        }
        
        vector<int>ans;
        ans.push_back(count);
        ans.push_back(maxprofit);
        return ans;
     } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends