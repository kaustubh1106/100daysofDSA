//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
      int mincost(vector<int>&cost,int n,vector<int> &dp){
         //base case
        if(n==0){
            return cost[0];
        }
        else if(n==1){
            return cost[1];
        }
        
        else if(dp[n]!=-1){
            return dp[n];
        }
        else{
            // step 2: dp vector me store kara liya
            dp[n] = min(mincost(cost,n-1,dp),mincost(cost,n-2,dp))+cost[n];
            return dp[n];
        }
      }
    int minCostClimbingStairs(vector<int>&cost ,int n) {
        //Write your code here
        //step 1 DP vector
        vector<int> DP(n+1,-1);
        int ans = min(mincost(cost,n-1,DP),mincost(cost,n-2,DP));
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends