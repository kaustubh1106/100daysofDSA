//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        if(M>N || N*6<M*7 && S>6){
            return -1;
        }
        if(M<=N){
            // N/M NUMBER OF DAYS CAN SURVIVE
            int tr = M*S;
            int days = tr/N;
            if(tr%N!=0){
                days++;
            }
            return days;
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends