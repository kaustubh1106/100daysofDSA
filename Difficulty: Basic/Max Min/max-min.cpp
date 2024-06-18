//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
   public:
    pair<int,int> check(int a[],int n, int l,int r){
        if(l==r){
            pair<int,int> p = make_pair(a[l],a[r]);
            return p;
        }
        else if(r==l+1){
            pair<int,int> p;
            p.first = min(a[l],a[r]);
            p.second = max(a[l],a[r]);
            return p;
        }
        else{
            int mid = (l+r)/2;
            pair<int,int> ans;
            pair<int,int> l1 = check(a,n,l,mid);
            pair<int,int> r1 = check(a,n,mid+1,r);
            ans.first = min(l1.first,r1.first);
            ans.second = max(l1.second,r1.second);
            return ans;
        }
    }
    int findSum(int a[], int n)
    {
    	//code here.
    	pair<int,int> ans = check(a,n,0,n-1);
    	return ans.first+ans.second;
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
	    int ans=ob.findSum(arr, n);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends