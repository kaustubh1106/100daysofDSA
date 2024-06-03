//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    vector<int> las(vector<int> A,int n){
        if(n==1){
            return A;
        }
        else{
            vector<int> ans;
            int i =0 ;
            while( i < A.size()){
                int prev = A[i];
                int count = 0; 
                while(i < A.size() && A[i]==prev){
                    count++;
                    i++;
                }
                ans.push_back(count);
                ans.push_back(prev);
               
            }
            return las(ans,n-1);
        }
    }
    string lookandsay(int n) {
          // code here
        vector<int> ans;
        ans.push_back(1);
        vector<int> result = las(ans,n);
        string res;
        for (int i = 0; i < result.size(); i++) {
        res += to_string(result[i]);
        }
        return res;
        
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends