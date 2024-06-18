//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    void helper(vector<int> &ans, int arr[], int n, int l , int r){
        if(l==r){
            if(arr[l]==l-1){
                ans.push_back(l);
            }
            return ;
        }
        else{
            int mid =(l+r)/2;
            helper(ans,arr,n,l,mid);
            helper(ans,arr,n,mid+1,r);
            return ;
        }
    }
	vector<int> valueEqualToIndex(int arr[], int n) {
	    // code here
	    vector<int> ans;
	    for(int i= 1 ; i<=n;i++){
	        if(arr[i-1]==i){
	            ans.push_back(i);
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.valueEqualToIndex(arr, n);
        if (ans.empty()) {
            cout << "Not Found";
        } else {
            for (int x: ans) {
                cout << x << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends