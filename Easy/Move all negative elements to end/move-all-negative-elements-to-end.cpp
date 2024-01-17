//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        // Your code goes here
        vector<int> p;
        vector<int> ne;
        for(int i=0;i<n;i++){
            if(arr[i]>=0){p.push_back(arr[i]);}
            else{
                ne.push_back(arr[i]);
            }
        }
        
        for(int i= 0;i<p.size();i++){
            arr[i]=p[i];
        }
        for(int i= p.size();i<p.size()+ne.size();i++){
            
            arr[i]=ne[i-p.size()];
        }
    }
};

//{ Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}

// } Driver Code Ends