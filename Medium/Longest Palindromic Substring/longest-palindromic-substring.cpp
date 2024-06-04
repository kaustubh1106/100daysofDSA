//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool checkPalindrome(int i , int j ,string s){
        if(i>=j){
            return true;
        }
        else{
            if(s[i]!=s[j]){
                return false;
            }
            return checkPalindrome(i+1,j-1,s);
        }

    }
    string longestPalindrome(string S){
        // code here 
        int n=S.length();
        int maxlen=1;
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        int l =0;
        int r =0;
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                //check in dp table
                if(dp[i][j]==0){
                    if(checkPalindrome(i,j,S)){
                        int curr_length = j-i+1;
                        if(curr_length>maxlen){
                            maxlen=curr_length;
                            l=i;
                            r=j;
                        }
                        else{}
                        dp[i][j]=1;
                    }
                }
            }
        }
        return S.substr(l,maxlen);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends