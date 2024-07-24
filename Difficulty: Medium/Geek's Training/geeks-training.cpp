//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     int rec(vector<vector<int>>& points, int ind,int last,vector<vector<int>>& dp){
        //base case
        if(ind == 0){
            int maxi= INT_MIN;
            for(int i = 0 ; i< 3;i++){
                if(i!=last){
                    maxi= max(points[0][i],maxi);
                }
            }
            return maxi;
        }
        if(dp[ind][last]!= -1) return dp[ind][last];
        int maxi= INT_MIN;
        for(int i = 0 ; i< 3;i++){
            if(i!=last){
                int p = points[ind][i] + rec(points,ind-1,i,dp);
                maxi = max(maxi, p);
            }
        }
        return dp[ind][last] = maxi;
        
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> dp(n+1, vector<int>(4,-1));
        return rec(points,n-1,3,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends