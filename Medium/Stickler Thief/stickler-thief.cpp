//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int solve(int arr[],int n,int i,int sum,vector<int>&dp){
        // base case
        if(i>=n){
            return sum;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        else{
            //include
            int sum1 = solve(arr,n,i+2,sum+arr[i],dp);
            // dp[arr[i]]= sum1;
            int sum2 = solve(arr,n,i+1,sum,dp);
            dp[i]= max(sum1,sum2);
            return dp[i];
        }
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
         // Your code here
        vector<int>dp(n+1);
        dp[0]=arr[0];
        dp[1]=max(arr[1], arr[0]);
        
        for(int i=2;i<n;i++)
        {
            dp[i]=max(arr[i]+dp[i-2], dp[i-1]);
        }
        
        return dp[n-1];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends