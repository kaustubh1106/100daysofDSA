//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int rightmost(int arr[],int n, int start,int end,int x){
        int mid = (start+end)/2;
        while(start<=end){
            if(arr[mid]==x){
                if(mid == n-1 || arr[mid + 1] != x){
                    return mid;
                }
                else{
                    start=mid+1;
                }
            }
            else if (arr[mid] < x) {
                start = mid + 1;  
            } else {
                end = mid - 1;  
            }
            mid = (start+end)/2;
        }
        return -1;
    }
    int leftmost(int arr[],int n, int start,int end,int x){
        int mid = (start+end)/2;
        while(start<=end){
            if(arr[mid]==x){
                if(mid == 0 || arr[mid - 1] != x){
                    return mid;
                }
                else{
                    end=mid-1;
                }
            }
            else if (arr[mid] < x) {
                start = mid + 1;  
            } else {
                end = mid - 1;  
            }
            mid = (start+end)/2;
        }
        return -1;
    }
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        vector<int> ans;
        int l = leftmost(arr,n,0,n-1,x);
        int r = rightmost(arr,n,0,n-1,x);
        ans={l,r};
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends