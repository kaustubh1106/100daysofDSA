//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool helper(string& A, string& B, string& C, int i, int j, int p, vector<vector<int>>& dp) {
    // If both A and B are fully traversed, return true
    if (i == A.size() && j == B.size()) {
        return true;
    }

    // If result is already computed, return it
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    // Match current character of C with A
    if (i < A.size() && A[i] == C[p]) {
        if (helper(A, B, C, i + 1, j, p + 1, dp)) {
            return dp[i][j] = 1;
        }
    }

    // Match current character of C with B
    if (j < B.size() && B[j] == C[p]) {
        if (helper(A, B, C, i, j + 1, p + 1, dp)) {
            return dp[i][j] = 1;
        }
    }

    // If neither matches, return false
    return dp[i][j] = 0;
}

bool isInterleave(string A, string B, string C) {
    int m = A.size();
    int n = B.size();
    int s = C.size();

    if (s != m + n) {
        return false;
    }

    // Initialize dp array with -1
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    return helper(A, B, C, 0, 0, 0, dp);
}

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends